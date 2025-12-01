/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 21:43:24 by kmummadi          #+#    #+#             */
/*   Updated: 2025/11/25 08:55:08 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../includes/AForm.hpp"
#include <exception>
#include <iostream>

class ShrubberyCreationForm : public AForm {
private:
  std::string _target;

public:
  // Constructors and Destructor
  ShrubberyCreationForm();
  ShrubberyCreationForm(const std::string &target);
  ShrubberyCreationForm(const ShrubberyCreationForm &form);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &form);
  ~ShrubberyCreationForm();

  // Execute
  void execute(Bureaucrat const &executor) const override;

  // Getters and Setters
  std::string &getTarget();
  void setTarget(const std::string &target);

  // Exceptions
  class FileException : public std::exception {
  public:
    const char *what() const noexcept override;
  };
};
