#include "../src/rectangle.h"

TEST(Shapes, CreateRectangle) {
  try {
        Rectangle(0, 1); //==> the argument should > 0 or the rectangle can't be build.
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("This is not a rectangle!", e);
    }
    ASSERT_NO_THROW(Rectangle(1, 1));
}

TEST(Shapes, AreaRectangle) {
  Rectangle rectangle(3, 4);
  ASSERT_EQ(12, rectangle.area());
}

TEST(Shapes, PerimeterRectangle) {
  Rectangle rectangle(3, 4);
  ASSERT_EQ(14, rectangle.perimeter());
}

TEST(Shapes, InfoRectangle) {
  Rectangle rectangle(3, 4);
  ASSERT_EQ("Rectangle (3.000, 4.000)", rectangle.info());
}

TEST(Shapes, RectangleTest){
  try{
    Shape * rectangle1 = new Rectangle(2, 4.5);
    Shape * rectangle2 = new Rectangle(3, 4.5);
    rectangle1->add(rectangle2);
    FAIL();
  }catch(std::string e){
    ASSERT_EQ("Can't support this operation.", e);
  }
  // delete rectangle1;
  // delete rectangle2;
}
