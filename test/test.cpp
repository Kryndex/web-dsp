#define CATCH_CONFIG_MAIN
#include <iostream>
#include "./lib/catch.hpp"
#include "../cpp/webdsp.cpp"

TEST_CASE("Testing grayScale function", "[grayScale]") {
  int len = 4;
  unsigned char data[] = { 12, 15, 199, 124 };
  unsigned char out[]  = { 12, 12, 12, 124 };
  grayScale(data, len);
  SECTION("R G and B should be equal") {
    for (int i = 0; i < len; i++) {
      REQUIRE( data[i] == out[i] );
    }
  }
}

TEST_CASE("Testing brighten function", "[brighten]") {
  int len = 4;
  int brightness = 15;
  unsigned char data[] = { 12, 15, 255, 255 };
  unsigned char out[]  = { 12 + brightness, 15 + brightness, 255, 255 };
  brighten(data, len, brightness);
  SECTION("R and G should be increased by brightness") {
    for (int i = 0; i < len; i++) {
      REQUIRE( data[i] == out[i] );
    }
  }

  unsigned char data2[] = { 255, 234, 121, 255 };
  brighten(data2, len, 100);
  SECTION("No value should be greater than 255") {
    for (int i = 0; i < len; i++) {
      REQUIRE( data2[i] <= 255 );
    }
  }
}

TEST_CASE("Testing invert function", "[invert]") {
  int len = 4;
  int max = 255;
  unsigned char data[] = {1, 2, 3, 255 };
  unsigned char out[] = {254, 253, 252, 255};
  invert(data, len);
  SECTION("R G B should be inverted") {
    for (int i = 0; i < len; i++) {
      REQUIRE( data[i] == out[i] );
    }
  }
}
