/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:49:54 by kmummadi          #+#    #+#             */
/*   Updated: 2025/11/25 18:50:47 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../includes/AForm.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm {
private:
  std::string _target;

public:
  // Constructors and Destructors
  PresidentialPardonForm();
  PresidentialPardonForm(const std::string &target);
  PresidentialPardonForm(const PresidentialPardonForm &form);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &form);
  ~PresidentialPardonForm();

  // Execute
  void execute(Bureaucrat const &executor) const override;

  // Getters and Setters
  std::string &getTarget();
  void setTarget(const std::string &target);
};
