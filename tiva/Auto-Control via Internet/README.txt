1. Required elements:
	* Code Composer Studio (version 7 is recommended).
	* Tivaware library.
	* TI v17.6.0.STS compiler.


2. To build succesfully this CCS project, user must change the include path ofTivaware
library by following way:

    * Click to the project folder in the [Project Explorer].
    * Press [Alt]+[Enter] to open [Properties] of the project.
    * Navigate to tab [Build]->[ARM Compiler]->[Include Options].
    * Replace the path '/home/antiaegis/ti/Tivaware' by your [Tivaware] location.
    * OK.