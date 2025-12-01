/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 22:26:52 by kmummadi          #+#    #+#             */
/*   Updated: 2025/11/25 19:12:58 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/utils.hpp"
#include <iostream>

int main() {
  section("CPP05 EX02 – AForm Execution Tests");

  // --------------------------------------------------------
  section("Test 1: Shrubbery – Successful execute");
  {
    try {
      Bureaucrat boss("Boss", 1);
      ShrubberyCreationForm f("garden");

      std::cout << boss << std::endl;
      std::cout << f << std::endl;

      boss.signForm(f);
      boss.executeForm(f);
    } catch (const std::exception &e) {
      colorprint(e.what(), RED);
    }
  }

  // --------------------------------------------------------
  section("Test 2: Shrubbery – Execute without signing");
  {
    try {
      Bureaucrat mid("Mid", 40);
      ShrubberyCreationForm f("backyard");

      std::cout << mid << std::endl;
      std::cout << f << std::endl;

      mid.executeForm(f); // should fail
    } catch (const std::exception &e) {
      colorprint(e.what(), RED);
    }
  }

  // --------------------------------------------------------
  section("Test 3: Shrubbery – Grade too low for execution");
  {
    try {
      Bureaucrat low("Low", 150);
      ShrubberyCreationForm f("terrace");

      low.signForm(f);
      low.executeForm(f); // should fail
    } catch (const std::exception &e) {
      colorprint(e.what(), RED);
    }
  }

  // --------------------------------------------------------
  section("Test 4: Robotomy – Random drilling");
  {
    try {
      Bureaucrat b("RoboMaster", 1);
      RobotomyRequestForm f("TargetX");

      b.signForm(f);
      b.executeForm(f); // should run drill, success/failure 50%
      b.executeForm(f); // run twice for randomness
      b.executeForm(f);
    } catch (const std::exception &e) {
      colorprint(e.what(), RED);
    }
  }

  // --------------------------------------------------------
  section("Test 5: Robotomy – Missing signature");
  {
    try {
      Bureaucrat b("Tester", 1);
      RobotomyRequestForm f("TargetY");

      b.executeForm(f); // should fail (not signed)
    } catch (const std::exception &e) {
      colorprint(e.what(), RED);
    }
  }

  // --------------------------------------------------------
  section("Test 6: Presidential Pardon – Successful");
  {
    try {
      Bureaucrat pres("President", 1);
      PresidentialPardonForm f("Prisoner42");

      pres.signForm(f);
      pres.executeForm(f);
    } catch (const std::exception &e) {
      colorprint(e.what(), RED);
    }
  }

  // --------------------------------------------------------
  section("Test 7: Presidential Pardon – Grade too low");
  {
    try {
      Bureaucrat low("Intern", 150);
      PresidentialPardonForm f("Nobody");

      low.signForm(f);    // should fail
      low.executeForm(f); // should also fail
    } catch (const std::exception &e) {
      colorprint(e.what(), RED);
    }
  }

  section("All EX02 tests finished");
  return (0);
}
