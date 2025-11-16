/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:10:41 by kmummadi          #+#    #+#             */
/*   Updated: 2025/11/15 22:26:44 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/utils.hpp"
#include <exception>
#include <iostream>

// Constructors and Destructors
Bureaucrat::Bureaucrat() : _name("NoName"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, const int &grade)
    : _name(name) {
  setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : _name(obj._name) {
  setGrade(obj._grade);
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj) {
  if (this != &obj) {
    _name = obj._name;
    setGrade(obj._grade);
  }
  return (*this);
}

Bureaucrat::~Bureaucrat() {}

// Getters and setters
int Bureaucrat::getGrade() const { return (_grade); }

std::string Bureaucrat::getName() const { return (_name); }

void Bureaucrat::setName(const std::string &name) { _name = name; }

void Bureaucrat::setGrade(const int &grade) {
  if (grade > 150)
    throw GradeTooLowException();
  else if (grade < 1)
    throw GradeTooHighException();
  else
    _grade = grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return ("Grade too low");
}

void Bureaucrat::incrementGrade() { setGrade(--_grade); }

void Bureaucrat::decrementGrade() { setGrade(++_grade); }

std::ostream &operator<<(std::ostream &output, const Bureaucrat &obj) {
  output << obj.getName() << ", bureaucrat grade " << obj.getGrade();
  return (output);
}
