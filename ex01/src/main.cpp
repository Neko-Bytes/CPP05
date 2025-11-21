/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 22:26:52 by kmummadi          #+#    #+#             */
/*   Updated: 2025/11/21 17:27:27 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include "../includes/utils.hpp"
#include <iostream>

int main() {
  section("CPP05 ex01 – Form Signing Tests");

  // Testing a valid form signing (bureaucrat grade high enough)
  section("Test 1: Successful signing");
  {
    try {
      Bureaucrat a("Alice", 40);
      Form f("TaxReturn", 50, 20);

      std::cout << a << std::endl;
      std::cout << f << std::endl;

      a.signForm(f);
      std::cout << f << std::endl;
    } catch (std::exception &e) {
      colorprint(e.what(), RED);
    }
  }

  // Testing signing when bureaucrat grade is too low
  section("Test 2: Signing fails (grade too low)");
  {
    try {
      Bureaucrat b("Bob", 120);
      Form f("TopSecret", 50, 25);

      std::cout << b << std::endl;
      std::cout << f << std::endl;

      b.signForm(f); // should fail
      std::cout << f << std::endl;
    } catch (std::exception &e) {
      colorprint(e.what(), RED);
    }
  }

  // Testing boundary: grade exactly equal to required
  section("Test 3: Boundary grade signing");
  {
    try {
      Bureaucrat c("Charlie", 50);
      Form f("SimpleForm", 50, 100);

      std::cout << c << std::endl;
      std::cout << f << std::endl;

      c.signForm(f); // should succeed
      std::cout << f << std::endl;
    } catch (std::exception &e) {
      colorprint(e.what(), RED);
    }
  }

  // Testing trying to sign an already signed form
  section("Test 4: Signing an already signed form");
  {
    try {
      Bureaucrat d("Diana", 10);
      Form f("Contract", 20, 50);

      d.signForm(f); // first time OK
      d.signForm(f); // second time is allowed but doesn't change signed state

      std::cout << f << std::endl;
    } catch (std::exception &e) {
      colorprint(e.what(), RED);
    }
  }

  // Testing constructor with invalid grades
  section("Test 5: Invalid form construction");
  {
    try {
      Form bad("FailForm", 0, 10); // invalid: grade < 1
    } catch (std::exception &e) {
      colorprint(e.what(), RED);
    }

    try {
      Form bad2("FailForm2", 10, 200); // invalid: grade > 150
    } catch (std::exception &e) {
      colorprint(e.what(), RED);
    }
  }

  section("All tests completed");
  return 0;
}
