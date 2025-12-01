/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:30:35 by kmummadi          #+#    #+#             */
/*   Updated: 2025/12/01 15:31:27 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/Intern.hpp"
#include "../includes/utils.hpp"
#include <iostream>

int main() {
  section("CPP05 EX03 – Intern and Form Creation Tests");

  Intern intern;
  Bureaucrat highGrade("HighGrade", 1);
  Bureaucrat midGrade("MidGrade", 50);

  // --------------------------------------------------------
  section("Test 1: Intern creates Shrubbery Creation Form (Success)");
  AForm *shrubberyForm = NULL;
  try {
    shrubberyForm = intern.makeForm("shrubbery creation", "Forest");
    if (shrubberyForm) {
      std::cout << *shrubberyForm << std::endl;
      highGrade.signForm(*shrubberyForm);
      highGrade.executeForm(*shrubberyForm);
    }
  } catch (const std::exception &e) {
    colorprint(e.what(), RED);
  }
  delete shrubberyForm;

  // --------------------------------------------------------
  section("Test 2: Intern creates Robotomy Request Form (Success and Execute)");
  AForm *robotomyForm = NULL;
  try {
    robotomyForm = intern.makeForm("robotomy request", "Bender");
    if (robotomyForm) {
      std::cout << *robotomyForm << std::endl;
      midGrade.signForm(*robotomyForm);  // Grade to sign is 45, MidGrade is 50
                                         // (should fail sign)
      highGrade.signForm(*robotomyForm); // Grade to sign is 45, HighGrade is 1
                                         // (should succeed)
      highGrade.executeForm(
          *robotomyForm); // Execute multiple times to test 50% chance
      highGrade.executeForm(*robotomyForm);
    }
  } catch (const std::exception &e) {
    colorprint(e.what(), RED);
  }
  delete robotomyForm;

  // --------------------------------------------------------
  section(
      "Test 3: Intern creates Presidential Pardon Form (Success and Execute)");
  AForm *pardonForm = NULL;
  try {
    pardonForm = intern.makeForm("presidential pardon", "Ford Prefect");
    if (pardonForm) {
      std::cout << *pardonForm << std::endl;
      highGrade.signForm(*pardonForm);
      highGrade.executeForm(*pardonForm);
    }
  } catch (const std::exception &e) {
    colorprint(e.what(), RED);
  }
  delete pardonForm;

  // --------------------------------------------------------
  section("Test 4: Intern tries to create an UNKNOWN Form (Failure)");
  AForm *unknownForm = NULL;
  try {
    unknownForm = intern.makeForm("nuclear blast request", "Earth");
    if (unknownForm)
      std::cout << *unknownForm << std::endl;
  } catch (const std::exception &e) {
    colorprint(e.what(), RED);
  }
  delete unknownForm; // Safe to delete NULL

  // --------------------------------------------------------
  section("Test 5: Execution attempt by low-grade bureaucrat");
  Bureaucrat lowGrade("LowGrade", 150);
  AForm *shrubberyTest = intern.makeForm("shrubbery creation", "Bush");
  if (shrubberyTest) {
    lowGrade.signForm(*shrubberyTest);  // Should fail to sign (required 145)
    highGrade.signForm(*shrubberyTest); // Force sign (required 145, grade 1)
    lowGrade.executeForm(
        *shrubberyTest); // Should fail to execute (required 137, grade 150)
  }
  delete shrubberyTest;

  section("All EX03 tests finished");
  return (0);
}
