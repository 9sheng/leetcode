// copy from leveldb/util/testharness.h

#ifndef TESTHARNESS_H_
#define TESTHARNESS_H_

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <string>
#include <vector>
#include <sys/stat.h>
#include <sys/types.h>

// An instance of Tester is allocated to hold temporary state during
// the execution of an assertion.
class Tester {
 private:
  bool ok_;
  const char* fname_;
  int line_;
  std::stringstream ss_;

 public:
  Tester(const char* f, int l)
      : ok_(true), fname_(f), line_(l) {
  }

  ~Tester() {
    if (!ok_) {
      fprintf(stderr, "%s:%d:%s\n", fname_, line_, ss_.str().c_str());
      exit(1);
    }
  }

  Tester& Is(bool b, const char* msg) {
    if (!b) {
      ss_ << " Assertion failure " << msg;
      ok_ = false;
    }
    return *this;
  }

#define BINARY_OP(name,op)                            \
  template <class X, class Y>                         \
  Tester& name(const X& x, const Y& y) {              \
    if (! (x op y)) {                                 \
      ss_ << " failed: " << x << (" " #op " ") << y;  \
      ok_ = false;                                    \
    }                                                 \
    return *this;                                     \
  }

  BINARY_OP(IsEq, ==)
  BINARY_OP(IsNe, !=)
  BINARY_OP(IsGe, >=)
  BINARY_OP(IsGt, >)
  BINARY_OP(IsLe, <=)
  BINARY_OP(IsLt, <)
#undef BINARY_OP

  // Attach the specified value to the error message if an error has occurred
  template <class V>
  Tester& operator<<(const V& value) {
    if (!ok_) {
      ss_ << " " << value;
    }
    return *this;
  }
};

#define ASSERT_TRUE(c) ::Tester(__FILE__, __LINE__).Is((c), #c)
#define ASSERT_EQ(a,b) ::Tester(__FILE__, __LINE__).IsEq((a),(b))
#define ASSERT_NE(a,b) ::Tester(__FILE__, __LINE__).IsNe((a),(b))
#define ASSERT_GE(a,b) ::Tester(__FILE__, __LINE__).IsGe((a),(b))
#define ASSERT_GT(a,b) ::Tester(__FILE__, __LINE__).IsGt((a),(b))
#define ASSERT_LE(a,b) ::Tester(__FILE__, __LINE__).IsLe((a),(b))
#define ASSERT_LT(a,b) ::Tester(__FILE__, __LINE__).IsLt((a),(b))

#define TCONCAT(a,b) TCONCAT1(a,b)
#define TCONCAT1(a,b) a##b

#define TEST(base,name)                                                   \
    class TCONCAT(_Test_,name) : public base {                            \
   public:void _Run();                                                    \
      static void _RunIt() {                                              \
        TCONCAT(_Test_,name) t;                                           \
        t._Run();                                                         \
      }                                                                   \
    };                                                                    \
    bool TCONCAT(_Test_ignored_,name) =                                   \
             ::RegisterTest(#base, #name, &TCONCAT(_Test_,name)::_RunIt); \
    void TCONCAT(_Test_,name)::_Run()

namespace {
struct Test {
  const char* base;
  const char* name;
  void (*func)();
};
std::vector<Test>* tests;
}

// Register the specified test.  Typically not used directly, but
// invoked via the macro expansion of TEST.
bool RegisterTest(const char* base, const char* name, void (*func)()) {
  if (tests == NULL) {
    tests = new std::vector<Test>;
  }
  Test t;
  t.base = base;
  t.name = name;
  t.func = func;
  tests->push_back(t);
  return true;
}

// Returns 0 if all tests pass.
// Dies or returns a non-zero value if some test fails.
int RunAllTests() {
  const char* matcher = getenv("LEVELDB_TESTS");

  int num = 0;
  if (tests != NULL) {
    for (size_t i = 0; i < tests->size(); i++) {
      const Test& t = (*tests)[i];
      if (matcher != NULL) {
        std::string name = t.base;
        name.push_back('.');
        name.append(t.name);
        if (strstr(name.c_str(), matcher) == NULL) {
          continue;
        }
      }
      fprintf(stderr, "==== Test %s.%s\n", t.base, t.name);
      (*t.func)();
      ++num;
    }
  }
  fprintf(stderr, "==== PASSED %d tests\n", num);
  return 0;
}

int main(int argc, char** argv) {
  return ::RunAllTests();
}

#endif  // TESTHARNESS_H_
