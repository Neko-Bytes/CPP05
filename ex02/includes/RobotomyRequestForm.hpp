/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 08:45:21 by kmummadi          #+#    #+#             */
/*   Updated: 2025/11/25 08:54:24 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../includes/AForm.hpp"
#include <iostream>

class RobotomyRequestForm : public AForm {
private:
  std::string _target;

public:
  // Constructors and Destructors
  RobotomyRequestForm();
  RobotomyRequestForm(const std::string &target);
  RobotomyRequestForm(const RobotomyRequestForm &form);
  RobotomyRequestForm &operator=(const RobotomyRequestForm &form);
  ~RobotomyRequestForm();

  // Execute
  void execute(Bureaucrat const &executor) const override;

  // Getters and Setters
  std::string &getTarget();
  void setTarget(const std::string &target);
};
