/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 17:31:21 by kmummadi          #+#    #+#             */
/*   Updated: 2025/11/26 17:36:53 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/utils.hpp"
#include <exception>
#include <iostream>

class Intern {
public:
  // Constructor and Destructor
  Intern();
  Intern(const Intern &obj);
  Intern &operator=(const Intern &obj);
  ~Intern();

  // Functions
  AForm *makeForm(const std::string &name, std::string target);
  class InvalidFormException : std::exception {
    const char *what() const noexcept override;
  };
};
