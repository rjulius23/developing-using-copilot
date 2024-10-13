# developing-using-copilot
This a repo to demonstrate working with coding assistants.

## Task 1
### Generate unit tests for the different functions
#### Option 1
* Go to one of the cpp files under the src folder
* Highlight the function that you would like to write tests for
* Use the copilot module and type in /tests and hit enter (or click on the arrow)
* Save the generated test under the tests folder
* Run make
* Run make test

#### Option 2
* Go to one of the cpp files under the src folder
* Highlight the function that you would like to write tests for
* Go to Copilot Chat and type in teh following prompt
  * Create a test plan for #selection based on the #file ... and for details refer to #file ...
  * For the source files you can refer to the cpp and header files
* Save the generated test under the tests folder
* Run make
* Run make test

## Task 2
### Optimize your code using Copilot
#### Option 1
* Go to one of the cpp files under the src folder
* Highlight the function that you would like to optimize (preferably you already wrote tests for it)
* Open Copilot chat and use teh following prompt:
  * Optimize for performance and minimal memory usage the #selection also explain what are you doing and why

## Task 3
### Try out /explain and /document as well on highlighted code

