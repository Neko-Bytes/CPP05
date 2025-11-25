/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 22:01:55 by kmummadi          #+#    #+#             */
/*   Updated: 2025/11/25 08:53:24 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include <fstream>

// Constructors and Destructors
ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("Shrubbery-Default", 145, 137), _target("Shrubbery-Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("Shrubbery-Default", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form)
    : AForm(form), _target(form._target) {}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &form) {
  if (this != &form)
    _target = form._target;
  return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

// Execute
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  int grade = executor.getGrade();

  if (this->isSigned() == false)
    throw AForm::FormException(FormException::NotSigned);
  if (grade > this->getGradeToSign() && grade > this->getGradeToExecute())
    throw AForm::FormException(FormException::GradeTooLow);
  else {
    std::ofstream file(_target + "_shrubbery");
    if (!file.is_open())
      ShrubberyCreationForm::FileException();

    file << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⢿⠿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
            "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⠛⠙⠛⠋⠙⠿⢿⡿⠿⠁⠀⠀⠀⠀⠀⠈⠙⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
            "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠁⠀⠀⠀⠀⠀⠀⠉⠙⠿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
            "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠛⠙⠋⠀⠀⠂⠀⠀⠀⠀⠄⠀⠀⠀⠀⠤⠉⠛⠶⣄⣠⣤⣤⠀⠀⠀⠀⠀⠀⠀⠻⢿⣿⣿⣿⣿⣿⣿⣿⣿\n"
            "⣿⣿⣿⣿⣿⣿⣿⣿⠟⠃⠀⠀⠀⢀⣀⠀⠀⠀⠀⣐⠶⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⣽⡯⡭⠄⠀⠀⠀⠀⠀⠀⠸⣿⣿⣿⣿⣿⣿⣿⣿\n"
            "⣿⣿⣿⣿⣿⣿⣏⠀⠀⠀⠀⠀⠀⠤⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠠⠄⠀⠀⠀⠀⠀⣼⣿⣿⣿⣿⣿⣿⣿\n"
            "⣿⣿⣿⣿⣿⣿⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠴⠆⠀⠀⠀⠀⠀⠀⠉⠈⠉⠀⠀⠀⠄⠀⠀⠀⠙⠿⣿⣿⣿⣿⣿⣿\n"
            "⣿⣿⣿⣿⡿⠿⠓⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠀⠀⠀⠁⠀⠀⠀⠀⠸⢿⣿⣿⣿⣿\n"
            "⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠴⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠂⠀⠀⠀⠀⠀⠺⢿⣿⣿⣿\n"
            "⣿⠿⠿⠛⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠰⣿⣿\n"
            "⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣹\n"
            "⣆⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡤⠓⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈\n"
            "⣿⣿⣿⡆⣠⡤⠀⠆⡀⠀⣀⠓⠄⢴⡆⠀⠀⠀⠀⠀⠀⠀⢴⡀⠀⢦⠀⠀⠀⠀⠀⠀⠀⢀⣠⣤⠀⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣶⣾\n"
            "⣿⣿⣿⣿⣿⣷⣶⣿⣿⣶⣿⣿⣷⣶⣤⣄⡀⢀⣤⣤⣴⣦⣄⡁⠀⠀⠀⡶⠀⢰⣿⣶⣴⣿⣿⣿⣦⠈⠁⠀⢀⣠⡀⠀⢀⣄⣀⢀⣠⣿⣿\n"
            "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣿⣿⣿⣿⣿⣿⣿⡄⠀⠈⢀⣴⣿⣿⣿⣿⣿⣿⣿⣷⣤⣤⣤⣼⣿⣿⣷⣾⣿⣿⣿⣿⣿⣿\n"
            "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
            "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
            "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⠿⠿⠛⠁⠀⠀⠙⠻⠿⠿⠿⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n";

    file.close();
  }
}

// Exception
const char *ShrubberyCreationForm::FileException::what() const noexcept {
  return ("File is not open.");
}

// Getters and Setters
std::string &ShrubberyCreationForm::getTarget() { return (_target); }

void ShrubberyCreationForm::setTarget(const std::string &target) {
  _target = target;
}
