/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 13:51:28 by kmummadi          #+#    #+#             */
/*   Updated: 2025/11/24 22:19:33 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/utils.hpp"

// Constructors
AForm::AForm()
    : _name("Default AForm"), _isSigned(false), _gradeToSign(150),
      _gradeToExecute(150) {}

AForm::AForm(const std::string &name, int gradeSign, int gradeExec)
    : _name(name), _isSigned(false), _gradeToSign(gradeSign),
      _gradeToExecute(gradeExec) {
  if (gradeSign < 1 || gradeExec < 1)
    throw GradeTooHighException();
  if (gradeSign > 150 || gradeExec > 150)
    throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
    : _name(other._name), _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
}

AForm &AForm::operator=(const AForm &other) {
  if (this != &other) {
    _isSigned = other._isSigned;
  }
  return (*this);
}

AForm::~AForm() {}

// Getters
const std::string &AForm::getName() const { return (_name); }

bool AForm::isSigned() const { return (_isSigned); }

int AForm::getGradeToSign() const { return (_gradeToSign); }

int AForm::getGradeToExecute() const { return (_gradeToExecute); }

// Core function
void AForm::beSigned(const Bureaucrat &b) {
  if (b.getGrade() > _gradeToSign)
    throw GradeTooLowException();
  if (_isSigned == true)
    throw AlreadySignedException();
  _isSigned = true;
  colorprint("[Success]: ", GREEN);
  std::cout << b.getName() << " has signed " << _name << std::endl;
}

const char *AForm::GradeTooLowException::what() const noexcept {
  return ("grade is too low to be signed");
}

const char *AForm::GradeTooHighException::what() const noexcept {
  return ("grade is too high to be signed");
}

const char *AForm::AlreadySignedException::what() const noexcept {
  return ("document has been already signed");
}

const char *AForm::FormException::what() const noexcept {
  switch (_t) {
  case GradeTooHigh:
    return ("grade is too high to be signed");
  case GradeTooLow:
    return ("grade is too low to be signed");
  case AlreadySigned:
    return ("document has been already signed");
  case NotSigned:
    return ("document hasn't been signed yet");
  }
}

// Output operator
std::ostream &operator<<(std::ostream &out, const AForm &f) {
  out << colortxt("AForm", ORANGE) << " \"" << f.getName() << "\""
      << " | " << colortxt("signed", ORANGE) << ": "
      << (f.isSigned() ? "yes" : "no") << " | "
      << colortxt("grade to sign", ORANGE) << ": " << f.getGradeToSign()
      << " | " << colortxt("grade to execute", ORANGE) << ": "
      << f.getGradeToExecute();
  return (out);
}
