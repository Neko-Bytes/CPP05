/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 13:51:28 by kmummadi          #+#    #+#             */
/*   Updated: 2025/11/21 16:59:17 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/utils.hpp"

// Constructors
Form::Form()
    : _name("Default Form"), _isSigned(false), _gradeToSign(150),
      _gradeToExecute(150) {}

Form::Form(const std::string &name, int gradeSign, int gradeExec)
    : _name(name), _isSigned(false), _gradeToSign(gradeSign),
      _gradeToExecute(gradeExec) {
  if (gradeSign < 1 || gradeExec < 1)
    throw GradeTooHighException();
  if (gradeSign > 150 || gradeExec > 150)
    throw GradeTooLowException();
}

Form::Form(const Form &other)
    : _name(other._name), _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
}

Form &Form::operator=(const Form &other) {
  if (this != &other) {
    _isSigned = other._isSigned;
  }
  return (*this);
}

Form::~Form() {}

// Getters
const std::string &Form::getName() const { return (_name); }

bool Form::isSigned() const { return (_isSigned); }

int Form::getGradeToSign() const { return (_gradeToSign); }

int Form::getGradeToExecute() const { return (_gradeToExecute); }

// Core function
void Form::beSigned(const Bureaucrat &b) {
  if (b.getGrade() > _gradeToSign)
    throw GradeTooLowException();
  if (_isSigned == true)
    throw AlreadySignedException();
  _isSigned = true;
  colorprint("[Success]: ", GREEN);
  std::cout << b.getName() << " has signed " << _name << std::endl;
}

const char *Form::GradeTooLowException::what() const noexcept {
  return ("grade is too low to be signed");
}

const char *Form::GradeTooHighException::what() const noexcept {
  return ("grade is too high to be signed");
}

const char *Form::AlreadySignedException::what() const noexcept {
  return ("document has been already signed");
}

// Output operator
std::ostream &operator<<(std::ostream &out, const Form &f) {
  out << colortxt("Form", ORANGE) << " \"" << f.getName() << "\""
      << " | " << colortxt("signed", ORANGE) << ": "
      << (f.isSigned() ? "yes" : "no") << " | "
      << colortxt("grade to sign", ORANGE) << ": " << f.getGradeToSign()
      << " | " << colortxt("grade to execute", ORANGE) << ": "
      << f.getGradeToExecute();
  return (out);
}
