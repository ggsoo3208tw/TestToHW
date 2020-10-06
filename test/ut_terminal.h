#include "../src/terminal.h"
TEST(Terminal, NotHaveShapes) {
  try {
      Terminal("perimeter inc");
      FAIL();
  }catch(std::string e) {
      ASSERT_EQ("invalid input", e);
  }
}
TEST(Terminal, NotHaveFeature) {
  try {
      Terminal("Ellipse (3, 4) Rectangle (5, 6) Triangle ([0,-3], [-3,0], [0,-4]) inc");
      FAIL();
  }catch(std::string e) {
      ASSERT_EQ("invalid input", e);
  }
}
TEST(Terminal, NotHaveOrder) {
  try {
      Terminal("Ellipse (3, 4) Rectangle (5, 6) Triangle ([0,-3], [-3,0], [0,-4]) area");
      FAIL();
  }catch(std::string e) {
      ASSERT_EQ("invalid input", e);
  }
}
TEST(Terminal, NotTrueToWightOrHeight) {
  try {
      Terminal("Ellipse (0, 0) Rectangle (-1, -2) area inc");
      FAIL();
  }catch(std::string e) {
      ASSERT_EQ("invalid input", e);
  }
}
/*
TEST(Terminal, Normal){
  Terminal terminal("Ellipse (5, 6) Rectangle (5, 6) Triangle ([0,-3], [-3,0], [0,-4]) perimeter inc");
  ASSERT_EQ("1.000\n4.000", terminal.showResult());
}
*/
/*------------------------------*/
TEST(Terminal, MyTest){
  Terminal terminal("Ellipse (2, 2) Rectangle (1, 2) Triangle ([0,-3], [-3,0], [0,-4]) area inc");
  ASSERT_EQ("12.566\n2.000\n", terminal.showResultTest());
}
