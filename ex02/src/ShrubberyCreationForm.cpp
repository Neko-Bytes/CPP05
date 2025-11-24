/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 22:01:55 by kmummadi          #+#    #+#             */
/*   Updated: 2025/11/24 23:27:54 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include <fstream>

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm() : _target("None") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form)
    : _target(form._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  int grade = executor.getGrade();

  if (this->isSigned() == false)
    throw AForm::FormException(FormException::NotSigned);
  if (grade < this->getGradeToExecute())
    throw AForm::FormException(FormException::GradeTooLow);
  else {
    std::ofstream file(_target + "shrubbery");
  }
}
