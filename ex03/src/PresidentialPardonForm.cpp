/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:51:40 by kmummadi          #+#    #+#             */
/*   Updated: 2025/11/25 19:17:35 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/utils.hpp"

// Constructors and Destructors
PresidentialPardonForm::PresidentialPardonForm()
    : AForm("Presidential-Default", 25, 5), _target("Presidential-Default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("Presidential-Default", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &form)
    : AForm(form), _target(form._target) {}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &form) {
  if (this != &form)
    _target = form._target;
  return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

// Execute
void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
  int grade = executor.getGrade();

  if (!this->isSigned())
    throw(AForm::FormException(FormException::NotSigned));
  if (grade > this->getGradeToSign() && grade > this->getGradeToExecute())
    throw(AForm::FormException(FormException::GradeTooLow));
  else {
    colorprint(_target + " has been pardoned by Zaphod Beeblebrox.", GREEN);
  }
}

// Getters and Setters
std::string &PresidentialPardonForm::getTarget() { return (_target); }

void PresidentialPardonForm::setTarget(const std::string &target) {
  _target = target;
}
