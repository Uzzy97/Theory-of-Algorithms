**_Theory of Algorithms 2020_**
<br>
**_Lecturer: Ian McLoughlin_**
<br>
**Student:** Usman Sattar
<br>
**Contact:** G00345816@gmit.ie
___
1. [ Introduction. ](#intro)
2. [ Run. ](#run)
3. [ Test. ](#test)
4. [ Algorithm. ](#algo)
5. [ Complexity. ](#comp)
6. [ References. ](#ref)

<a name="stat"></a>
#####  Problem Statement
<p> You must write a program in the C programming language that calculates
the MD5 hash digest of an input. The algorithm is specified in the Request
For Comments 1321 document supplied by the Internet Engineering Task
Force. The only pre-requisite is that your program performs the algorithm
— you are free to decide what input the algorithm should be performed on.
I suggest you allow the user to input some free text or a filename via the
command line.</p>

<a name="intro"></a>
##### Introduction
The repository contains two folders, SHA256-Algorithm and MD5. The repository also consists of a .gitignore file and a readme.md file which contains the research conducted while carrying out this project. Shortly, I will be going through everything in the repository in-depth. Finally, there is a folder called images , which I needed to upload sketches of my diagrams and understanding of the algorithm.

###### MD5 Folder
This folder consists of a file called MD5.c It is written in the C Programming language. Anyone will be able to understand of what is going through within the file as it is thoroughly commented of what each step does within the code. I understand for a junior software developer, it may be difficult to understand. Further within this documentation, the algorithm will be explained with the usage of diagrams.

###### SHA256-Algorithm Folder
This folder contains all of the work I have completed while conducting this project. The files created in this folder are a run through of Ian McLoughlin's weekly lab videos which were taken place online. I found them very helpful, you can play, pause, rewind back if you find it difficult to understand. Within this folder, we go through the SHA256 algorithm and we also go through padding and understand how padding plays its part in this project.

###### .gitignore File
The gitignore file is a text file that tells Git which files/folders (or patterns) to ignore in a project. It's usually used to avoid committing transient files from your working directory that aren't useful to other collaborators, such as compilation products, temporary files IDEs create, etc.

###### MIT License
A short and simple permissive license with conditions only requiring preservation of copyright and license notices. Licensed works, modifications, and larger works may be distributed under different terms and without source code.

###### README.md
A short documentation for the MD5 algorithm. It consists of research and materials which helped to complete this project. It strictly contains details of the MD5 Hashing.

###### Images Folder
The images folder contains the sketches and diagrams of the MD5 which helped me understand it better. These sketches and diagrams can be viewed in the README.md.
___

<a name="run"></a>
##### Run
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
<img align="left" src="https://github.com/Uzzy97/Theory-of-Algorithms/blob/master/VM-Instances.PNG">
<br>
 - Download project using terminal or by downloading zip folder.
 - Open through command prompt (terminal)
 - Direct yourself into the MD5 folder
 - `make MD5` (Compiles The Program)
 - `./MD5 --test` Runs the Program
 
 ___
   
<a name="test"></a>
##### Test
In this section, I am going explain the tests which are included within the code.

| Tests         | Expected Results           | Pass/Fail  |
| ------------- |:--------------------------:| ----------:|
| --help        | right-aligned              | PASS       |
| --test        | centered                   | PASS       |
 
 ___
   
<a name="algo"></a>
##### Algorithm
In this section, we are going to run through the main algorithm(s) within the code. Where appropriate further explanation will be given with diagram(s).
 
 ___
   
<a name="comp"></a>
##### Complexity
This is the most important section within the report. You must fully understand of what is happening within this section of complexity. We are going to fully analyse the complexity of the MD5 algorithm, including the complexity of algorithms that attempt to reverse the
algorithm.
 
 ___
   
<a name="ref"></a>
##### References




