#include "ShrubberyCreationForm.hpp"
#include "Form.hpp"
#include "Bureaucrat.hpp"

// Constructors

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : Form("ShrubberyCreationForm", 145, 137, target)
{}

ShrubberyCreationForm::ShrubberyCreationForm()
    : Form("Default", 145, 137, "Default")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
    : Form(copy.getName(), copy.getGradeToSign(), copy.getGradeToExecute(), copy.getTarget())
{}

// Deconstructor

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << ORANGE << "WIPE: " << *this << RESET << std::endl;
}

// Member Functions

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if (!isSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    std::ofstream outFile(getTarget() + "_shrubbery");
    for (int i = 0; i < 5; i++)
		{
			outFile <<
			"         v" << std::endl <<
			"        >X<" << std::endl <<
			"         A" << std::endl <<
			"        d$b" << std::endl <<
			"      .d\\$$b." << std::endl <<
			"    .d$i$$\\$$b." << std::endl <<
			"       d$$@b" << std::endl <<
			"      d\\$$$ib" << std::endl <<
			"    .d$$$\\$$$b" << std::endl <<
			"  .d$$@$$$$\\$$ib." << std::endl <<
			"      d$$i$$b" << std::endl <<
			"     d\\$$$$@$b" << std::endl <<
			"  .d$@$$\\$$$$$@b." << std::endl <<
			".d$$$$i$$$\\$$$$$$b." << std::endl <<
			"        ###" << std::endl <<
			"        ###" << std::endl <<
			"        ###" << std::endl <<
		std::endl;
    }
    outFile.close();
    std::cout << "Shrubbery created at " << getTarget() << "!\n";
}

// Operator overload

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& Form)
{
     os << "Form: " << Form.getName()
        << ", Signed: " << (Form.isSigned() ? "Yes" : "No")
        << ", Grade to sign: " << Form.getGradeToSign()
        << ", Grade to execute: " << Form.getGradeToExecute()
        << ", Target: " << Form.getTarget();
    return os;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& Form)
{
    if (this != &Form)
    {
        this->setSign(Form.isSigned());
    }
    std::cout << GREEN << "Created: " << *this << RESET << std::endl;
    return *this;
}