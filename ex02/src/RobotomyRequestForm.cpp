/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 08:55:48 by kmummadi          #+#    #+#             */
/*   Updated: 2025/11/25 09:06:59 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/utils.hpp"
#include <fstream>

// Constructors and Destructors
RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Robotomy-Default", 145, 137), _target("Robotomy-Default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("Robotomy-Default", 145, 137), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form)
    : AForm(form), _target(form._target) {}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &form) {
  if (this != &form)
    _target = form._target;
  return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

// Execute
void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  static bool success = false;
  int grade = executor.getGrade();

  if (!this->isSigned())
    throw(AForm::FormException(FormException::NotSigned));
  if (grade > this->getGradeToSign() && grade > this->getGradeToExecute())
    throw(AForm::FormException(FormException::GradeTooLow));
  else {
    if (success)
      colorprint(_target + " has been Robotomized.", GREEN);
    else
      colorprint(_target + " could not be Robotomized.", RED);
  }
}

// Getters and Setters
std::string &RobotomyRequestForm::getTarget() { return (_target); }

void RobotomyRequestForm::setTarget(const std::string &target) {
  _target = target;
}
