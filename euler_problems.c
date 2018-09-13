// Joshua Weiner
// Systems pd04
// Work 01
// 2018 - 09 - 11

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Find the sum of all the multiples of 3 or 5 below 1000.
int problem_1() {
  int total = 0; //sum of all multiples, originally 0
  for (int i = 0; i < 1000; i ++) { //for loop for each integer from 0 (inclusive) to 999 (below 1000)
    if (i % 3 == 0) { //if integer is a multiple of three
      total += i; //add to sum of multiples
    }
    else if (i % 5 == 0) { //if integer is a multiple of five
      total += i;//add to sum of multiples
    }
  } //exit for loop

  return total; //return total
}

bool is_divisible(int num, int divisor) { //helper function for problem_5()
  if (num % divisor == 0) {
    return true;
  }
  else {
    return false;
  }
}

//What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
int problem_5() {
  int smallest_number = 1; //start at one
  bool is_smallest = false; //is this the smallest number divisible by numbers 1-20 evenly

  while (is_smallest == false) {

    for (int divisor = 1; divisor < 21; divisor ++) { //test each divisor

      if (is_divisible(smallest_number, divisor) == false) { //if number is not evenly divisible
        is_smallest = false;
        smallest_number ++; //go to next number
        break; //dont waste memory, break this for loop
      }
      else {
        is_smallest = true;
      }
    }
  }
  return smallest_number; //return smallest integer evenly divisible by 1-20

}

//Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
int problem_6() {
  int sum_of_squares = 0;
  int square_of_sums = 0;

  int total = 0; //used for square of sums, this will be total of sums

  for (int sos = 1; sos < 101; sos ++) { //for each integer 1-100, square and add to sum_of_squares
    sum_of_squares += pow(sos, 2);
  }

  for (int sos = 1; sos < 101; sos ++) { //for each integer 1-100, add to total of sums
    total += sos;
  }
  square_of_sums = pow(total, 2); //square sums... i.e. square_of_sums

  return square_of_sums - sum_of_squares; //return difference
}

int main() {
  printf("Problem 1: %d \n", problem_1());
  printf("Problem 5: %d \n", problem_5());
  printf("Problem 6: %d \n", problem_6());
  return 0;
}
