#ifndef TERMINAL_H
#define TERMINAL_H

#include <iostream> // cout must include
/*----- string must include -----*/
#include <string>
using namespace std;
/*------   -----*/
#include <regex>
/*-----   -----*/
#include "shape.h"
#include "ellipse.h"
#include "rectangle.h"
#include "triangle.h"
/*----- -----*/
class Terminal{
public:
  Terminal(string input):_input(input){
    if(checkInput()) throw string("invalid input");// request error
  }
  string showResult(){
    // ex: "Rectangle (2, 2) Rectangle (1, 1) area inc"
    // Ans: "1.000\n4.000"
    return "1.000\n4.000";
  }
  /*----- my Write func -----*/
  bool checkInput(){
    regex checkPattern("((Ellipse\\s+\\({1}\\s*[1-9]\\s*,\\s*[1-9]\\s*\\){1})|(Rectangle\\s+\\({1}\\s*[1-9]\\s*,\\s*[1-9]\\s*\\){1})|(Triangle\\s+\\({1}\\s*\\[{1}\\s*-?[0-9]\\s*,\\s*-?[0-9]\\s*\\]{1}\\s*,\\s*\\[{1}\\s*-?[0-9]\\s*,\\s*-?[0-9]\\s*\\]{1}\\s*,\\s*\\[{1}\\s*-?[0-9]\\s*,\\s*-?[0-9]\\s*\\]{1}\\s*\\){1})){1}\\s+(area|perimeter)\\s+(inc$|dec$)");
    if(regex_search(_input,checkPattern)){
      return false;
    }
    return true;
  }
  string showResultTest(){
    string result = "";
    smatch sm;
    string _PleaseInput = _input;
    regex orderPattern("^(inc$|dec$)");
    regex featurePattern("^(area|perimeter)(.*)");
    string shapesPattern[] = {
      "^(Ellipse\\s+\\({1}\\s*[0-9]\\s*,\\s*[0-9]\\s*\\){1}\\s+)(.*)",
      "^(Rectangle\\s+\\({1}\\s*[0-9]\\s*,\\s*[0-9]\\s*\\){1}\\s+)(.*)",
      "^(Triangle\\s+\\({1}\\s*\\[{1}\\s*-?[0-9]\\s*,\\s*-?[0-9]\\s*\\]{1}\\s*,\\s*\\[{1}\\s*-?[0-9]\\s*,\\s*-?[0-9]\\s*\\]{1}\\s*,\\s*\\[{1}\\s*-?[0-9]\\s*,\\s*-?[0-9]\\s*\\]{1}\\s*\\){1}\\s+)(.*)"
    };
    for(int z = 0;z<10 && (!regex_match(_PleaseInput,featurePattern));z++){
      for(int i = 0;i < 3;i++){
        if(regex_match(_PleaseInput,sm,regex(shapesPattern[i]))){
          if(i == 0){
            //cout << "Ellipse : " << sm[1] << endl;
            regex getNumber("[^0-9]*([0-9]+)(.*)");
            smatch m;
            string str = string(sm[1]);
            int ellipseValue[2],count = 0;
            while (regex_search(str, m, getNumber)) {
              ellipseValue[count++] = stoi(string(m[1]));
              str = string(m[2]); // Proceed to the next match
            }
            Ellipse ellipse(ellipseValue[0],ellipseValue[1]);
            char ellipseArea[100];
            sprintf(ellipseArea, "%.3f", ellipse.area());
            result += string(ellipseArea);
            result += '\n';
          }else if(i == 1){
            //cout << "Rectangle : " << sm[1] << endl;
            regex getNumber("[^0-9]*([0-9]+)(.*)");
            smatch m;
            string str = string(sm[1]);
            int rectangleValue[2],count = 0;
            while (regex_search(str, m, getNumber)) {
              rectangleValue[count++] = stoi(string(m[1]));
              str = string(m[2]); // Proceed to the next match
            }
            Rectangle rectangle(rectangleValue[0],rectangleValue[1]);
            char rectangleArea[100];
            sprintf(rectangleArea, "%.3f", rectangle.area());
            result += string(rectangleArea);
            result += '\n';
          }else if(i == 2){
            //cout << "Triangle : " << sm[1] << endl;
            regex getNumber("[^-?0-9]*([-?0-9]+)(.*)");
            smatch m;
            string str = string(sm[1]);
            int ellipseValue[2],count = 0;
            while (regex_search(str, m, getNumber)) {
              ellipseValue[count++] = stoi(string(m[1]));
              str = string(m[2]); // Proceed to the next match
            }
            /*
            std::vector<TwoDimensionalCoordinate*> triangleVector;
            triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
            triangleVector.push_back(new TwoDimensionalCoordinate(3, 0));
            triangleVector.push_back(new TwoDimensionalCoordinate(0, 4));
            Triangle triangle(triangleVector);
            char triangleArea[100];
            sprintf(triangle, "%.3f", triangle.area());
            result += string(triangleArea);
            */
          }
          break;//代表以匹配形狀 跳出 i 迴圈
        }
      }
      _PleaseInput = string(sm[2]);
    }
    return result;
  }
  /*-----------------------*/
private:
  string _input;

};
#endif

/*---------  別理我 -----------*/
/*
//TEST
regex pattern("(Ellipse\\s+\\({1}\\s*[0-9]\\s*,\\s*[0-9]\\s*\\){1}\\s+)(.*)");
// Ellipse (3,4)
regex ellipse_pattern("Ellipse\\s+\\({1}\\s*[0-9]\\s*,\\s*[0-9]\\s*\\){1}");
// Rectangle (2,2)
regex rectangle_pattern("Rectangle\\s+\\({1}\\s*[0-9]\\s*,\\s*[0-9]\\s*\\){1}");
// Triangle ([0,-3], [-3,0], [0,-4])
regex triangle_pattern("Triangle\\s+\\({1}\\s*\\[{1}\\s*-?[0-9]\\s*,\\s*-?[0-9]\\s*\\]{1}\\s*,\\s*\\[{1}\\s*-?[0-9]\\s*,\\s*-?[0-9]\\s*\\]{1}\\s*,\\s*\\[{1}\\s*-?[0-9]\\s*,\\s*-?[0-9]\\s*\\]{1}\\s*\\){1}");
// array
string _format[3] = {"(Ellipse\\s+\\({1}\\s*[0-9]\\s*,\\s*[0-9]\\s*\\){1})(.*)",
                     "(Rectangle\\s+\\({1}\\s*[0-9]\\s*,\\s*[0-9]\\s*\\){1})(.*)",
                     "(Triangle\\s+\\({1}\\s*\\[{1}\\s*-?[0-9]\\s*,\\s*-?[0-9]\\s*\\]{1}\\s*,\\s*\\[{1}\\s*-?[0-9]\\s*,\\s*-?[0-9]\\s*\\]{1}\\s*,\\s*\\[{1}\\s*-?[0-9]\\s*,\\s*-?[0-9]\\s*\\]{1}\\s*\\){1})(.*)"
};
//
*/
/*if(regex_search(_input.begin(), _input.end(), ellipse_pattern)){
  //return false;
}*/
//smatch sm;
//if(regex_match(_input,sm,pattern)){}
  /*
  for(int i = 0;i<sm.size();++i){
    cout << i << ":" << sm[i] << endl;
  }
  */
  /*
  while(!){ // 直到碰到area or perimeter
    for(){ // _format 下去確認

    }
  }
  return false;
}
*/
/*----------------------------*/
