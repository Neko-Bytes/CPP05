/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 21:43:24 by kmummadi          #+#    #+#             */
/*   Updated: 2025/11/24 23:23:56 by kmummadi         ###   ########.fr       */
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
  ShrubberyCreationForm &operator=(const AForm &form);
  ~ShrubberyCreationForm();

  void execute(Bureaucrat const &executor) const override;

  // Exceptions
  class FileException : public std::exception {
  public:
    enum Type { FileCantBeOpened, FileCantBeRead };
    FileException(Type t);
    const char *what() const noexcept override;

  private:
    Type _t;
  };
};
