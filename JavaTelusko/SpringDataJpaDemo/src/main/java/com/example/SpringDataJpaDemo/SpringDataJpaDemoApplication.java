package com.example.SpringDataJpaDemo;

import com.example.SpringDataJpaDemo.model.Student;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.ApplicationContext;

import java.util.Optional;

@SpringBootApplication
public class SpringDataJpaDemoApplication {

	public static void main(String[] args) {
		ApplicationContext context = SpringApplication.run(SpringDataJpaDemoApplication.class, args);

		StudentRepo studentRepo = (StudentRepo) context.getBean(StudentRepo.class);

//		Student s1 = context.getBean(Student.class);
//		s1.setRollNo(101);
//		s1.setMarks(78);
//		s1.setName("Nilava");
//
		Student s2 = context.getBean(Student.class);
		s2.setRollNo(102);
		s2.setMarks(85);
		s2.setName("Aman");
//
//		Student s3 = context.getBean(Student.class);
//		s3.setRollNo(103);
//		s3.setMarks(78);
//		s3.setName("Deep");
//
//		studentRepo.save(s1);
//		studentRepo.save(s2);
//		studentRepo.save(s3);


		// * Fetch all data from Database
		System.out.println("------------------------");
		System.out.println("find all students -- " + studentRepo.findAll());

		// * Fetch particular student
		// ! the id may not be present and hence the query may return null so we do not write the below statement
		// System.out.println(studentRepo.findById(103));
		System.out.println("------------------------");
		Optional<Student> s = studentRepo.findById(104);
		System.out.println("find a particular student -- " + s.orElse(new Student()));

		// * Fetch by name (not a primary key)
		System.out.println("------------------------");
		System.out.println("find using a non primary key -- " + studentRepo.findByName("Nilava"));


		// * Update a particular student
		// ! 1st this fires a select query to check if the row actually exists
		// ! if there is no row then it inserts a new row else it updates the existing row
		System.out.println("------------------------");
		studentRepo.save(s2);

		// * Delete a particular student
		// ! 1st this fires a select query to check if the row actually exists
		// ! if there is a row it deletes the row
		System.out.println("------------------------");
		studentRepo.delete(s2);

		System.out.println("------------------------");
	}

}

