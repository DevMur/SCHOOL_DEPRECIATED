#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "Rectangle.h"

//
// TEST_CASE ( "Factorials are computed", "[factorial]") {
//   REQUIRE( Factorial(2) == 2 );
//   REQUIRE( Factorial(3) == 6 );
// }

TEST_CASE ( "Make a rectangle", "[rectangle]") {
  Point p1, p2;
  p1.x = 0;
  p1.y = 0;
  p2.x = 3;
  p2.y = 3;
  Rectangle test = Rectangle(p1, p2);
  int width = 3;
  int height = 3;
  p2.x = 2;
  p2.y = 4;
  Rectangle overlapping_rectangle = Rectangle(p1, p2);
  p1.x = 4;
  p2.x = 7;
  p2.y = 3;
  Rectangle non_overlapping_rectangle = Rectangle(p1, p2);
  int area_of_test = 9;
  //int area_of_non_overlapping = 9;
  //int area_of_overlapping = 8;
  int expanded_area = 25;
  int shrunk_area = 9;
  REQUIRE ( test.GetWidth() == width );
  REQUIRE ( test.GetHeight() == height );
  REQUIRE ( test.Overlaps(overlapping_rectangle) == true );
  REQUIRE ( test.Overlaps(non_overlapping_rectangle) == false );
  REQUIRE ( test.CalculateArea() == area_of_test );
  test.Expand();
  REQUIRE ( test.CalculateArea() == expanded_area );
  test.Shrink();
  test.Shrink();
  REQUIRE ( test.CalculateArea() == 1 );
}
