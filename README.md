# NewPort  
*A play on “New Portfolio” (and, yes, a nod to Newports) – my computer science project portfolio*

## Table of Contents
- [CS-210 – Clockering Time](./CS-210/P1%20Clockering%20Time/)
- [CS-230 – Airgead Banking App](./CS-230/P2%20Airgead%20Banking%20App/)
- [CS-230 – Grocery Tracking](./CS-230/P3%20Grocery%20Tracking/)
- [CS-230 – Draw It or Lose It](./CS-230/P4%20Draw%20It%20or%20Lose%20It/)
- [CS-250 – Sprint Review and Retrospective](./CS-250/)
- [CS-300 – DSA: Analysis and Design](./CS-300/)

## CS-210 & CS-230 Portfolio Projects

This repository contains my projects from my time in CS-210: Programming Languages. Each project exhibits my ability to write safe, efficient, and maintainable code in C++. Although I came into the course with prior programming experience in JavaScript, Python, jQuery, and their libraries, working with C++ challenged me to approach familiar concepts in a lower level, strongly typed environment. This helped me increase my understanding of memory management, efficiency, and best practices in structured programming.

### [Project 1 (P1) – Clockering Time](./CS-210/P1%20Clockering%20Time/)

**Summary:**
This project calculated and displayed time in both 12-hour and 24-hour formats while handling user input and formatting requirements.

**Reflection:**
- **What I did well:** I kept my code modular and readable by separating formatting logic into functions.
- **Enhancements:** I could improve input validation to handle unexpected or invalid entries more gracefully.
- **Challenges:** Getting the time formatting correct without off-by-one errors took testing and debugging, but breaking the logic into smaller functions solved it.
- **Transferable skills:** This reinforced the importance of modular design and formatting, which applies across all programming languages.

### [Project 2 (P2) – Airgead Banking App](./CS-230/P2%20Airgead%20Banking%20App/)


**Summary:**
This project simulated an investment calculator that showed how balances grow with and without monthly deposits. It involved looping, arithmetic operations, and clear formatted reporting.

**Reflection:**
- **What I did well:** I designed output reports that were easy to read and professional.
- **Enhancements:** I could expand the app to include additional investment options or integrate error handling for non-numeric inputs.
- **Challenges:** The compound interest formula was initially tricky, but I used my math background and pseudocode planning to make the implementation easier.
- **Transferable skills:** I practiced writing financial logic that could be applied to real-world fintech applications.

### [Project 3 (P3) – Grocery Tracking](./CS-230/P3%20Grocery%20Tracking/)

**Summary:**
This project tracked grocery items and their frequencies, reading from an input file and writing frequency data to an output file. It also displayed results in a histogram.

**Reflection:**
- **What I did well:** I implemented file input/output effectively and wrote code that was well-documented and structured.
- **Enhancements:** I could improve efficiency by using unordered maps or alternative data structures for faster lookups.
- **Challenges:** Managing file I/O while ensuring the program handled missing or incorrect files was the hardest part, but testing edge cases solved the issue.
- **Transferable skills:** File handling, data storage, and using maps/dictionaries are concepts that transfer directly to web development and Python work I’ve done before.

### Overall Reflection

While the programming concepts were familiar from my experience in JavaScript, Python, and jQuery, applying them in C++ required me to think differently about memory, efficiency, and type safety. This course helped me grow into a more well-rounded developer by strengthening my ability to:

- Write code that is maintainable, readable, and adaptable.
- Use modular design to make programs easier to test and debug.
- Reflect on challenges and find solutions using documentation, problem decomposition, and prior programming knowledge.

These projects represent important steps in building my portfolio and demonstrate transferable skills that apply across languages, projects, and professional software development.

### CS-230 – Software Design Journal: *Draw It or Lose It*

**Client Summary**  
The Gaming Room wanted to expand its Android game *Draw It or Lose It* into a web-based, multi-platform application. The new system needed to support multiple teams and players, enforce unique names across all entities, and function consistently across Windows, macOS, Linux, and mobile devices.

**What I Did Well**  
I developed a clear and organized software design document that effectively described the system architecture, UML domain model, and technical reasoning behind design patterns such as the Singleton and inheritance. My explanations of scalability, portability, and distributed environments were particularly strong.

**How the Design Document Helped Development**  
Writing the design document before coding helped me plan a clean, maintainable structure. Mapping relationships between the classes early on made implementation smoother and ensured the system met requirements for uniqueness and scalability.

**What I Would Revise**  
If I were to revise the project, I would add a persistence and networking layer to demonstrate how data storage and client-server communication would work in a live environment. This would make the design more complete and production-ready.

**Meeting User Needs**  
I analyzed the client’s requirements—scalability, reliability, and multi-platform functionality—and built the design to satisfy each. Considering the user’s needs ensures that the software is functional, efficient, and user-friendly across all supported platforms.

**Approach to Software Design**  
I applied object-oriented principles, UML modeling, and modular planning throughout the project. In future work, I plan to continue using these strategies, starting with visual models and pseudocode before coding, to ensure clarity and efficiency in design.

**Linked Document**  
[CS 230 Project Software Design Document](./CS-230/P4%20Draw%20It%20or%20Lose%20It/CS%20230%20Project%20Software%20Design.docx)

## CS-250: Software Development Lifecycle – [Sprint Review and Retrospective Reflection](./CS-250/Sprint%20Review%20and%20Retrospective.docx)

This course taught me how to interpret user needs by translating high-level requirements into clear, testable user stories that focus on delivering user value. Learning how to write and refine user stories helped me keep development work aligned with stakeholder expectations and prevented scope confusion during development. The course also showed me how an Agile approach supports effective software development through iterative progress, frequent feedback, and adaptability using practices such as sprint planning, reviews, and retrospectives. Understanding these processes helped me see how teams can continuously improve while reducing risk and responding to change more effectively. Additionally, I learned that being a successful team member in software development requires open communication, respect for defined roles, consistent contribution, and flexibility when adapting to new information, all of which are essential for strong collaboration in Agile teams.

## CS-300: DSA – Analysis and Design

This course focused on analyzing and designing efficient data structure solutions based on program requirements. I learned how evaluate vectors, hash tables, and binary search trees by comparing their runtime and memory characteristics to determine the most appropriate structure for a given problem.

### CS-300 - Project One - [Runtime Memory Analysis](./CS-300/Project%20One/)

In Project One, I ran a detailed runtime analysis comparing worst-case and average-case performance when loading and validating course data. Based on this evaluation, I recommended a Binary Search Tree to support efficient searching and natural alphanumeric ordering.

### CS-300 - Project Two - [BST Course Catalog Implementation](./CS-300/Project%20Two/)

In Project Two, I implemented a Binary Search Tree in C++ to load course data from a CSV file, print all courses in sorted alphanumeric order using in-order traversal, and display individual course information with prerequisites. This project reinforced my understanding of algorithmic efficiency, recursive traversal, and designing maintainable, structured programs.