package com.example.SpringDataJpaDemo;

import com.example.SpringDataJpaDemo.model.Student;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;
import org.springframework.stereotype.Repository;

import java.util.List;

@Repository
public interface StudentRepo extends JpaRepository<Student, Integer> {

    @Query("select s from Student s where s.name = ?1")
    List<Student> findByName(String name);
}


/*
* JPQL (Java Persistence Query Language) is a query language that looks like SQL but operates on Java objects/entities instead of database tables.
* It's part of the JPA specification.
* The key difference from SQL --
        * SQL queries tables and columns: SELECT * FROM job_post WHERE req_experience > 2
        * JPQL queries entities and their fields: SELECT j FROM JobPost j WHERE j.reqExperience > 2
* Notice: JobPost (the Java class name, capitalized) instead of job_post (the table name),
* and j.reqExperience (the Java field name, camelCase) instead of req_experience (the column name).
* JPQL is database-agnostic — it doesn't know or care whether you're running MySQL, PostgreSQL, or Oracle underneath.
* Hibernate translates your JPQL into the actual SQL dialect for whatever database you're connected to.
 */
