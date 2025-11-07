/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:10:41 by kmummadi          #+#    #+#             */
/*   Updated: 2025/11/07 18:17:00 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

// Constructors and Destructors
Bureaucrat::Bureaucrat() {
  _name = "None";
  _grade = 0;
}

Bureaucrat::Bureaucrat(const std::string &name, const int &grade) {
  _name = name;
  setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) {
  _name = obj._name;
  setGrade(obj._grade);
}

Bureaucrat::~Bureaucrat() {}

// Getters and setters
int Bureaucrat::getGrade() const { return (_grade); }

std::string Bureaucrat::getName() const { return (_name); }

void Bureaucrat::setName(const std::string &name) { _name = name; }

void Bureaucrat::setGrade(const int &grade) {}
