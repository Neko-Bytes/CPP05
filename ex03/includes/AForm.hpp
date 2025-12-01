/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 13:51:08 by kmummadi          #+#    #+#             */
/*   Updated: 2025/11/24 22:14:27 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>
#include <string>

// Forward declaration
class Bureaucrat;

class AForm {
private:
  const std::string _name;
  bool _isSigned;
  const int _gradeToSign;
  const int _gradeToExecute;

public:
  // Constructors and Destructor
  AForm();
  AForm(const std::string &name, int gradeSign, int gradeExec);
  AForm(const AForm &obj);
  AForm &operator=(const AForm &obj);
  virtual ~AForm();

  // Getters
  virtual const std::string &getName() const;
  virtual bool isSigned() const;
  virtual int getGradeToSign() const;
  virtual int getGradeToExecute() const;

  // Signing
  virtual void beSigned(const Bureaucrat &obj);
  virtual void execute(const Bureaucrat &executor) const = 0;

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

  class FormException : public std::exception {
  public:
    enum type { GradeTooHigh, GradeTooLow, AlreadySigned, NotSigned };
    FormException(type t);
    const char *what() const noexcept override;

  private:
    type _t;
  };
};

std::ostream &operator<<(std::ostream &out, const AForm &f);
