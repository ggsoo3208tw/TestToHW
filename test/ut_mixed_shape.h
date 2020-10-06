#include "../src/shape.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include "../src/ellipse.h"
#include "../src/sort.h"
#include "../src/mixed_shape.h"

class MixedShapeTest : public ::testing::Test {
protected:
  void SetUp() override {
     r34 = new Rectangle(3, 4);
     r22 = new Rectangle(2, 2);
     e1010 = new Ellipse(2, 1);
     std::vector<TwoDimensionalCoordinate*> triangleVector;
     triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
     triangleVector.push_back(new TwoDimensionalCoordinate(3, 0));
     triangleVector.push_back(new TwoDimensionalCoordinate(0, 4));
     t345 = new Triangle(triangleVector);
  }

  void TearDown() override {
      delete r34;
      delete r22;
      delete t345;
      delete e1010;
  }

  Shape * r34;
  Shape * r22;
  Shape * t345;
  Shape * e1010;
};

TEST_F(MixedShapeTest, CreateMixedShape){
  MixedShape mbox;
  ASSERT_EQ(0, mbox.getNumberOfComponents());
}
TEST_F(MixedShapeTest, CreateMixedShapeAsAShape){
  Shape * mbox = new MixedShape();
  ASSERT_EQ(0, ((MixedShape *)mbox)->getNumberOfComponents());
}
TEST_F(MixedShapeTest, AddShapeToMixedShape){
  MixedShape mbox;
  mbox.add(r34);
  ASSERT_EQ(1, mbox.getNumberOfComponents());
}
TEST_F(MixedShapeTest, MixedShapeArea){
  Shape * mbox = new MixedShape();
  mbox->add(r34);
  ASSERT_EQ(12, mbox->area());
}
TEST_F(MixedShapeTest, RectangelTest){

}
