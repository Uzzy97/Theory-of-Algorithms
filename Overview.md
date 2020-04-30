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
This folder consists of a file called MD5.c It is written in the C Programming language. Anyone will be able to understand of what is going through within the file as it is thoroughly commented of what each step does within the code. I understand for a junior software developer, it may be difficult to understand. Further within this documentation, the algorithm will be explained with the usage of diagrams. Within this folder there are test files which will be needed to test out the program, further details will be given below in the test section.

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
<img align="left" src="https://github.com/Uzzy97/Theory-of-Algorithms/blob/master/Images/VM-Instances.PNG">
<br>
 - Download project using terminal or by downloading zip folder.
 - Open through command prompt (terminal)
 - Direct yourself into the MD5 folder
 - `make MD5` (Compiles the program)
 - `./MD5 --help` Information regarding the program and instructions to run the program
 - `./MD5 --test` Runs the program, takes in a string and converts it into hash<br>
When the above command is run, user will be asked to enter file name. A list of file name will be printed out to input. The consistency of each file is below in the test section.
 
 ___
   
<a name="test"></a>
##### Test
In this section, we go through the different tests that are being carried out. The `./MD5 --test` offers the user to enter a file name that they wish to test. There are some test files already created, you may go ahead and test them out. User can also create their own test files and run them to see the outcome.

###### List of Files Already Created
<br>1. <b>empty</b> ("")<br>
The output should be: **_d41d8cd98f00b204e9800998ecf8427e_**<br><br>
<br>2. <b>a</b> ("a")<br>
The output should be: **_0cc175b9c0f1b6a831c399e269772661_**<br><br>
<br>3. <b>abc</b> ("abc")<br>
The output should be: **_900150983cd24fb0d6963f7d28e17f72_**<br><br>
<br>4. <b>messageDigest</b>("message digest")<br>
The output should be: **_f96b697d7cb7938d525a2f31aaf161d0_**<br><br>
<br>5. <b>alpha</b> ("abcdefghijklmnopqrstuvwxyz")<br>
The output should be: **_c3fcd3d76192e4007dfb496cca67e13b_**<br><br>
<br>6. <b>alphaNum</b> ("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789")<br>
The output should be: **_d174ab98d277d9f5a5611c2c9f419d9f_**<br><br>
<br>7. <b>num</b> ("12345678901234567890123456789012345678901234567890123456789012345678901234567890")<br>
The output should be: **_57edf4a22be3c955ac49da2e2107b67a_**<br><br>

| Tests | Expected Results | Pass/Fail  |
| :---: |:---:| :---: |
| Hash Output | Output should match as above | FAIL |
| Wong File Name | Couldn't open file | PASS |
| Invalid Argument | Invalid Command | PASS |
| No Argument | Expects Argument | PASS |
| --help | Information for user to follow | PASS |
| --test | Prompts user to enter file name | PASS |

To test if result is correct, refer to: https://www.md5hashgenerator.com
 
 ___
   
<a name="algo"></a>
##### Algorithm
In this section, we are going to run through the main algorithm(s) within the code. Where appropriate further explanation will be given with diagram(s).<br>
The MD5 hashing algorithm is a one-way cryptographic feature that accepts an input message of any length and returns a fixed-length digest value to be used to authenticate the original message as the output. The MD5 hash function was originally intended to be used as a secure cryptographic hash algorithm for digital signature authentication. To verify data integrity and prevent unintended data manipulation, MD5 has been deprecated for uses other than as a non-cryptographic checksum. While originally developed as a cryptographic message authentication code algorithm for use on the internet, for use as a cryptographic checksum, MD5 hashing is no longer considered reliable because researchers have demonstrated techniques that can easily produce MD5 collisions on commercial off - the-shelf computers.

![MD5 Algorithm](https://github.com/Uzzy97/Theory-of-Algorithms/blob/master/Images/MD5-Algorithm.jfif)
 - x[ ] -> Some part of P.T (Plain Text)
 - MD - > Output message digest
 ###### Functions (Logical)
 - F(B, C, D) - (B ^ C) v (>B ^ D)
 - G(B, C, D) - (B ^ D) v (C ^ > D)
 - H(B, C, D) - B ⊕ C ⊕ D
 - I(B, C, D) - C ⊕ (B V > D)
 
 - ⊕ - XOR (Exclusive or)
 
  ###### MD5 Steps
  The following five steps are preformed to compute the message digest of the message.
  1. Append padding bits
  2. Append Length
  3. Initialize MD Buffer
  4. Process message in 16-word blocks
  5. Output
 
 ___
     
<a name="comp"></a>
##### Complexity
<p>This is the most important section within the report. You must fully understand of what is happening within this section of complexity. We are going to fully analyse the complexity of the MD5 algorithm, including the complexity of algorithms that attempt to reverse the algorithm.</p>

### What The Code Consists?
<p>First we add in the necessary imports needed. Than Constants For Md5 Transform Routine are defined, these are used in the FF, GG, HH, II functions. Next we have the 64 pre-defined hash values which also get called in the FF, GG, HH, II values. Following the pre-defined hash values, we have a union block, which is a sixty-four byte block of memory, accessed with different types. The nextblock method goes through if statements. First we check if the status is equal to finish. Then, if the status is equal to PAD0 we then need an all-padding block without the one bit. Change status to finsh and return 1.</p>
<p>We test that at the end of this we can apply all the padding in the last block if statement changes status to PAD0 and returns 1.
Each transformation is called 16 times starting with round 1: FF, round 2: GG, round 3: HH and round 4: II
The next feature present in this program is the writeToFile feature in which chars are transferred.</p>
We have a hashFile() method, in this method we test out the different tests available. User in asked to enter a file name from the options and the result will be printed out. If there is no file available to access, an error message is printed out to the user.
Finally, the last method is the main method. In the main method we are writing out command line arguments. The two command line arguments included in the program are --help and --test

###### Comparison
| Keys For Comparison | MD5 | SHA |
| :---:         |     :---:      |          :---: |
| Security   | Less Secure Than SHA     | High Secure Than MD5    |
| Message Digest Length     | 128 Bits       | 160 Bits      |
| Attacks Required To Find Out Original Message| 2(128) Bit Operations Required To Break|2(160) Bit Operations Required To Break|
| Attacks To Try And Find Two Messages Producing The Same MD| 2(64) Bit Operations Required To Break|2(80) Bit Operations Required To Break|
| Speed | Faster, Only 64 Iterations| Slower Than MD5, Required 80 Iterations|
| Successful Attacks So Far | Attacks Reported To Some Extents| No Such Attack Report Yet|


###### Reversing an MD5 hash
MD5 was invented in 1992 and the first flaw was discovered in 1996. In 2010 the CMU Software Engineering Institute declared that MD5 was “cryptographically broken and unsuitable for further use.” It’s still being used, though not as much. MD5 still makes a useful checksum, though it’s not cryptographically secure.
Hash functions are not reversible in general. MD5 is a 128-bit hash, and so it maps any string, no matter how long, into 128 bits.
 ___
   
<a name="ref"></a>
##### References
- https://github.com/ianmcloughlin/sha256<br>
Weekly lab videos provided by lecturer.
- https://www.youtube.com/watch?v=53O9J2J5i14&t=226s#<br>
Explanation of the MD5 algorithm (31.29 Minute Video).
- https://searchsecurity.techtarget.com/definition/MD5<br>
Explanation of the MD5 algorithm.
- https://www.johndcook.com/blog/2019/01/24/reversing-an-md5-hash/<br>
Reversing an MD5 hash
- https://tools.ietf.org/html/rfc1321<br>
MD5 Message-Digest Algorithm
- https://www.md5hashgenerator.com/<br>
To test for correct hash value
- https://stackoverflow.com/questions/2948156/algorithm-complexity-security-md5-or-sha1/37235104<br>
Algorithm complexity and security<br><br><br><br>



&copy; Written By: Usman Sattar 2020
