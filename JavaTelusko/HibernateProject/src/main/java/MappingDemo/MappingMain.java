package MappingDemo;

import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;
import org.hibernate.cfg.Configuration;

public class MappingMain {
    public static void main(String[] args) {

        MappingLaptop l1 = new MappingLaptop();
        l1.setLid(1);
        l1.setBrand("Asus");
        l1.setModel("Rog");
        l1.setRam(16);

        MappingAlien a1 = new MappingAlien();
        a1.setAid(101);
        a1.setAname("Nilava");
        a1.setTech("Java");
        a1.setMappingLaptop(l1);

        SessionFactory sf = new Configuration()
                .addAnnotatedClass(MappingDemo.MappingAlien.class)
                .addAnnotatedClass(MappingDemo.MappingLaptop.class)
                .configure()
                .buildSessionFactory();

        Session session = sf.openSession();
        Transaction transaction = session.beginTransaction();

        session.merge(l1);
        session.merge(a1);
        transaction.commit();

        session.close();
        sf.close();

        System.out.println(a1);
    }
}
