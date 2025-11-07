/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 15:13:22 by kmummadi          #+#    #+#             */
/*   Updated: 2025/11/07 15:20:59 by kmummadi         ###   ########.fr       */
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
  ~Bureaucrat();

  // Getters and setters
  std::string getName() const;
  int getGrade() const;
  void setName(const std::string &name);
  void setGrade(const int &grade);

  // Other
  void incrementGrade(int grade);
  void decrementGrade(int grade);

  // Exception classes
  class GradeTooHighException : public std::exception {
  public:
    virtual const what *() const throw();
  };
};

std::ostream &operator<<(std::ostream &output, const Bureaucrat &obj);
void section(std::string name);
