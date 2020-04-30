# Calculation of the MD5 digest of an input

### Problem Statement
<strong><em><p>We are instructed write a program in the C programming language that calculates the MD5 hash digest of an input. The algorithm is specified in the Request For Comments 1321 document supplied by the Internet Engineering Task Force. The only pre-requisite is that your program performs the algorithm — you are free to decide what input the algorithm should be performed on. We are also suggested to allow the user to input some free text or a filename via the command line.</p></em></strong>

1. [ Compiling Instructions ](#comp)
2. [ MD5 Hashing Algorithm ](#hash)
3. [ Project Plan ](#proj)
4. [ References ](#ref)

___
<a name="comp"></a>
### Compiling Instuctions
This project is runnable on both Linux and Windows operating system. To start of with the project, one can download this project either by downloading the zip folder or through terminal.

**_Clone with HTTPS_**
1. Copy GitHub project link: `https://github.com/Uzzy97/Theory-of-Algorithms.git`
2. Open Command Prompt terminal on your device. Choose where you wish to clone the project. I would advice desktop as it is easy to access.
3. Run the following command: `git clone https://github.com/Uzzy97/Theory-of-Algorithms.git`

**_Download ZIP Folder_**
1. Go to GitHub Repository: `https://github.com/Uzzy97/Theory-of-Algorithms`
2. Top right-hand side you will have an option to Clone or Download, click that and Download Zip
3. Alternatively, copy and paste this link `https://github.com/Uzzy97/Theory-of-Algorithms/archive/master.zip`. It will automatically start downloading the zip folder.

**_Instruction To Compile_**
<br>
This project was created using VM instance using Google Cloud Platform. This decision was taken becuase we get to learn about instances and how to use them.
<br>
 - Download project using terminal or by downloading zip folder.
 - Open through command prompt (terminal)
 - Direct yourself into the MD5 folder
 - `make MD5` (Compiles the program)
 - `./MD5 --help` Information regarding the program and instructions to run the program
 - `./MD5 --test` Runs the program, takes in a string and converts it into hash<br>
When the above command is run, user will be asked to enter file name. A list of file name will be printed out to input. The consistency of each file is below in the test section.
___
<a name="hash"></a>
### What is a MD5 hashing algorithm?
The MD5 hashing algorithm is a one-way cryptographic feature that accepts an input message of any length and returns a fixed-length digest value to be used to authenticate the original message as the output. The MD5 hash function was originally intended to be used as a secure cryptographic hash algorithm for digital signature authentication. To verify data integrity and prevent unintended data manipulation, MD5 has been deprecated for uses other than as a non-cryptographic checksum. While originally developed as a cryptographic message authentication code algorithm for use on the internet, for use as a cryptographic checksum, MD5 hashing is no longer considered reliable because researchers have demonstrated techniques that can easily produce MD5 collisions on commercial off - the-shelf computers.

![](https://cdn.ttgtmedia.com/rms/onlineImages/security-md5_hashing.jpg)

### How MD5 Works
The MD5 message digest hashing algorithm processes data in 512-bit blocks, broken down into 16 words composed of 32 bits each. The output from MD5 is a 128-bit message digest value.

![](https://github.com/Uzzy97/Theory-of-Algorithms/blob/master/Images/MD5-Algorithm.jfif)
<a name="proj"></a>
### Project Plan
<p>Firstly I conducted the research relating to the MD5 Algorithm. Once I was comfortable in understanding how the algorithm worked, I began constructing the program in C Programming Language. I started and completed the project by using the Google Cloud Platform, using a VM Instance.</p>
<p>Due to Covid-19, there were new arrangements in place. Therefore I needed to restructure my plan. Now the MD5 program must accept command line arguments. While I was working towards completing the project, I had to add in command line argument. There was a new requirement of a report that must be called overview.md in my repository. This Markdown document contains a report on my project, pitched at students in the year below me. 

- Report: https://github.com/Uzzy97/Theory-of-Algorithms/blob/master/Overview.md
 
<a name="ref"></a>
### References:
* https://github.com/ianmcloughlin/sha256
* https://www.youtube.com/watch?v=53O9J2J5i14&t=226s#
* https://searchsecurity.techtarget.com/definition/MD5


by Usman Sattar
