class Department {
    // private readonly id: string;
    // private name: string;
    private employees: string[] = [];

    constructor(private readonly id: string, public name: string) {
        // this.id = id;
        // this.name = n;
    }

    describe(this: Department) {
        console.log(`Department : (${this.id}) + ${this.name}`);
    }

    addEmployee(employee: string) {
        this.employees.push(employee);
    }

    printEmployeeInformation() {
        console.log(this.employees.length);
        console.log(this.employees);
    }
};



class ITDepartment extends Department {
    constructor(id: string, public admins: string[]) {
        super(id, "IT Department");
    }
}

class AccountingDepartment extends Department {
    constructor(id: string, public reports: string[]) {
        super(id, "Accounting Department");
    }

    addReports(report: string) {
        this.reports.push(report);
    }

    printReport() {
        console.log(this.reports);
    }
}

const it = new ITDepartment("d1", ["nilava"]);
// console.log(it);
it.addEmployee("nilava");
it.addEmployee("tandrima");
it.describe();
it.printEmployeeInformation();

console.log(it);


const accounting = new AccountingDepartment('d2', []);
accounting.addReports("something went wrong ....");
accounting.printReport();

// const accountingCopy = { name: "Dummy", describe: it.describe };
// accountingCopy.describe();