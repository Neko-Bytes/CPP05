/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 13:51:08 by kmummadi          #+#    #+#             */
/*   Updated: 2025/11/21 16:50:25 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>
#include <string>

// Forward declaration
class Bureaucrat;

class Form {
private:
  const std::string _name;
  bool _isSigned;
  const int _gradeToSign;
  const int _gradeToExecute;

public:
  // Constructors and Destructor
  Form();
  Form(const std::string &name, int gradeSign, int gradeExec);
  Form(const Form &obj);
  Form &operator=(const Form &obj);
  ~Form();

  // Getters
  const std::string &getName() const;
  bool isSigned() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;

  // Signing
  void beSigned(const Bureaucrat &obj);

  // Exception Classes
  class GradeTooHighException : public std::exception {
  public:
    const char *what() const noexcept override;
  };

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const noexcept override;
  };

  class AlreadySignedException : public std::exception {
  public:
    const char *what() const noexcept override;
  };
};

std::ostream &operator<<(std::ostream &out, const Form &f);
