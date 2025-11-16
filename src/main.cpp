/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 22:26:52 by kmummadi          #+#    #+#             */
/*   Updated: 2025/11/15 22:27:13 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/utils.hpp"
#include <iostream>

int main() {
  section("CPP05 ex00 – Bureaucrat Tests");

  // Testing normal construction with a valid grade
  section("Test 1: Valid constructor");
  {
    try {
      Bureaucrat a("Alice", 42);
      std::cout << a << std::endl;
    } catch (std::exception &e) {
      colorprint(e.what(), RED);
    }
  }

  // Testing constructor with grade < 1
  section("Test 2: Grade too high (<1)");
  {
    try {
      Bureaucrat b("Bob", 0);
      std::cout << b << std::endl;
    } catch (std::exception &e) {
      colorprint(e.what(), RED);
    }
  }

  // Testing constructor with grade > 150
  section("Test 3: Grade too low (>150)");
  {
    try {
      Bureaucrat c("Charlie", 200);
      std::cout << c << std::endl;
    } catch (std::exception &e) {
      colorprint(e.what(), RED);
    }
  }

  // Testing grade increment at boundary (2 -> 1 OK, 1 -> 0 throws)
  section("Test 4: incrementGrade()");
  {
    try {
      Bureaucrat d("Diana", 2);
      std::cout << d << std::endl;

      d.incrementGrade();
      std::cout << d << std::endl;

      d.incrementGrade(); // should throw
    } catch (std::exception &e) {
      colorprint(e.what(), RED);
    }
  }

  // Testing grade decrement at boundary (149 -> 150 OK, 150 -> 151 throws)
  section("Test 5: decrementGrade()");
  {
    try {
      Bureaucrat e("Ethan", 149);
      std::cout << e << std::endl;

      e.decrementGrade();
      std::cout << e << std::endl;

      e.decrementGrade(); // should throw
    } catch (std::exception &e) {
      colorprint(e.what(), RED);
    }
  }

  // Testing low or high grade as parameter for the constructor
  section("Test 6: Invalid constructor");
  {
    try {
      Bureaucrat a("Sarah", -1);
      std::cout << a << std::endl;
    } catch (std::exception &e) {
      colorprint(e.what(), RED);
    }
  }

  section("Test 7: Invalid constructor");
  {
    try {
      Bureaucrat a("Sarah", 151);
      std::cout << a << std::endl;
    } catch (std::exception &e) {
      colorprint(e.what(), RED);
    }
  }

  section("All tests completed");
  return 0;
}
