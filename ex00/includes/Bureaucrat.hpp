/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 15:13:22 by kmummadi          #+#    #+#             */
/*   Updated: 2025/11/15 22:04:42 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>

class Bureaucrat {
private:
  std::string _name;
  int _grade;

public:
  // Constructors and Destructors
  Bureaucrat();
  Bureaucrat(const std::string &name, const int &grade);
  Bureaucrat(const Bureaucrat &obj);
  Bureaucrat &operator=(const Bureaucrat &obj);
  ~Bureaucrat();

  // Getters and setters
  std::string getName() const;
  int getGrade() const;
  void setName(const std::string &name);
  void setGrade(const int &grade);

  // Other
  void incrementGrade();
  void decrementGrade();

  // Exception classes
  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw() override;
  };

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw() override;
  };
};

std::ostream &operator<<(std::ostream &output, const Bureaucrat &obj);
