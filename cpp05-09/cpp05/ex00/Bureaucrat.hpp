#pragma once
#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <string>
#include <iostream>
#include <exception>

const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string RESET = "\033[0m";
const std::string ORANGE = "\033[38;5;208m";

class Bureaucrat
{

    private:
        const std::string   Name;
        int                 Grade;

    public:
        Bureaucrat(const std::string& _Name, const int& _Grade);
        virtual ~Bureaucrat();
        const std::string&  getName(void);
        const int&          getGrade(void);
        void incrementGrade(void);
        void decrementGrade(void);
        Bureaucrat();
        Bureaucrat& operator=(const Bureaucrat& copy);
        Bureaucrat(const Bureaucrat &copy);
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& copy);

#endif