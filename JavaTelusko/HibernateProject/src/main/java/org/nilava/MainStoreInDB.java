package org.nilava;

import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;
import org.hibernate.cfg.Configuration;

public class MainStoreInDB {
        @SuppressWarnings("ConvertToTryWithResources")
        public static void main(String[] args) {

                /*
                 * Student s1 = new Student();
                 * s1.setRollNo(33);
                 * s1.setsAge(5);
                 * s1.setSname("Pooh");
                 * 
                 * // Configuration cfg = new Configuration();
                 * // cfg.addAnnotatedClass(org.nilava.Student.class);
                 * // cfg.configure();
                 * // SessionFactory sf = cfg.buildSessionFactory();
                 * 
                 * // optimization for the above 4 lines --
                 * SessionFactory sf = new Configuration()
                 * .addAnnotatedClass(org.nilava.Student.class)
                 * .configure()
                 * .buildSessionFactory();
                 * 
                 * Session session = sf.openSession();
                 * 
                 * Transaction transaction = session.beginTransaction();
                 * session.persist(s1);
                 * transaction.commit();
                 * 
                 * session.close();
                 * sf.close();
                 * 
                 * System.out.println(s1);
                 */

                // fetch data from database --
                /*
                 * SessionFactory sf = new Configuration()
                 * .addAnnotatedClass(org.nilava.Student.class)
                 * .configure()
                 * .buildSessionFactory();
                 * 
                 * Session session = sf.openSession();
                 * Student s2 = null;
                 * s2 = session.find(Student.class, 29);
                 * 
                 * session.close();
                 * sf.close();
                 * 
                 * System.out.println(s2);
                 */

                // update data from database --
                // in the .merge function if we give a new data then it will insert it and if we
                // give an existing data then it will update it
                // Student s1 = new Student();
                // s1.setSname("Tumpi");
                // s1.setRollNo(32);
                // s1.setsAge(25);
                //
                // SessionFactory sf = new Configuration()
                // .addAnnotatedClass(org.nilava.Student.class)
                // .configure()
                // .buildSessionFactory();
                //
                // Session session = sf.openSession();
                // Transaction transaction = session.beginTransaction();
                //
                // session.merge(s1);
                // transaction.commit();
                //
                // session.close();
                // sf.close();
                //
                // System.out.println(s1);

                // delete data from database --
                Student s1 = new Student();

                SessionFactory sf = new Configuration()
                                .addAnnotatedClass(org.nilava.Student.class)
                                .configure()
                                .buildSessionFactory();

                Session session = sf.openSession();
                s1 = session.find(Student.class, 33);

                Transaction transaction = session.beginTransaction();

                session.remove(s1);
                transaction.commit();

                session.close();
                sf.close();

                System.out.println(s1);

        }
}
