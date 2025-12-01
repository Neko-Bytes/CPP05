/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 17:36:59 by kmummadi          #+#    #+#             */
/*   Updated: 2025/11/26 17:38:26 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"
#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/utils.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern &obj) { (void)obj; }

Intern &Intern::operator=(const Intern &obj) {
  (void)obj;
  return (*this);
}

Intern::~Intern() {}

AForm *Intern::makeForm(const std::string &name, std::string target) {
  std::string names[3] = {"shrubbery creation", "robotomy request",
                          "presidential pardon"};

  AForm *(*formcreator[3])(const std::string &) = {
      [](const std::string &form) -> AForm * {
        return (new ShrubberyCreationForm(form));
      },
      [](const std::string &form) -> AForm * {
        return (new RobotomyRequestForm(form));
      },
      [](const std::string &form) -> AForm * {
        return (new PresidentialPardonForm(form));
      }};

  for (int i = 0; i < 3; ++i) {
    if (name == names[i]) {
      colorprint("Intern has created " + name + " form.", GREEN);
      return (formcreator[i](target));
    }
  }
  throw(InvalidFormException());
}

const char *Intern::InvalidFormException::what() const noexcept {
  return ("Invalid form");
}
