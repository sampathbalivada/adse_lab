-- Table 1: Employees
CREATE TABLE Employees (
    employee_id SERIAL PRIMARY KEY,
    first_name VARCHAR(50) NOT NULL,
    last_name VARCHAR(50) NOT NULL,
    email VARCHAR(100) UNIQUE,
    phone_number VARCHAR(20),
    hire_date DATE NOT NULL,
    job_id VARCHAR(10) NOT NULL,
    salary NUMERIC(8, 2) NOT NULL,
    department_id INT
);

-- Table 2: Departments
CREATE TABLE Departments (
    department_id SERIAL PRIMARY KEY,
    department_name VARCHAR(50) NOT NULL,
    location_id INT
);

-- Table 3: Locations
CREATE TABLE Locations (
    location_id SERIAL PRIMARY KEY,
    street_address VARCHAR(100),
    postal_code VARCHAR(20),
    city VARCHAR(50) NOT NULL,
    state_province VARCHAR(50),
    country_id CHAR(2)
);

-- Table 4: Products
CREATE TABLE Products (
    product_id SERIAL PRIMARY KEY,
    product_name VARCHAR(100) NOT NULL,
    description TEXT,
    price NUMERIC(10, 2) NOT NULL,
    stock_quantity INT NOT NULL,
    is_available BOOLEAN DEFAULT TRUE
);

-- Table 5: Orders
CREATE TABLE Orders (
    order_id SERIAL PRIMARY KEY,
    customer_id INT NOT NULL,
    order_date TIMESTAMP NOT NULL,
    total_amount NUMERIC(10, 2) NOT NULL,
    status VARCHAR(20) DEFAULT 'Pending'
);

-- Insert data into Employees
INSERT INTO Employees (first_name, last_name, email, phone_number, hire_date, job_id, salary, department_id) VALUES
('John', 'Doe', 'john.doe@example.com', '123-456-7890', '2023-01-15', 'IT_PROG', 60000.00, 1),
('Jane', 'Smith', 'jane.smith@example.com', '987-654-3210', '2022-11-20', 'SA_REP', 75000.00, 2),
('Peter', 'Jones', 'peter.jones@example.com', '555-123-4567', '2023-03-10', 'MK_MGR', 90000.00, 3),
('Mary', 'Johnson', 'mary.johnson@example.com', '111-222-3333', '2023-05-01', 'HR_REP', 55000.00, 4),
('David', 'Williams', 'david.williams@example.com', '444-555-6666', '2021-09-01', 'FI_ACCOUNT', 65000.00, 5),
('Emily', 'Brown', 'emily.brown@example.com', '777-888-9999', '2023-08-12', 'AD_VP', 120000.00, 1),
('Michael', 'Davis', 'michael.davis@example.com', '222-333-4444', '2020-07-18', 'PU_CLERK', 45000.00, 2),
('Jessica', 'Miller', 'jessica.miller@example.com', '666-777-8888', '2023-10-25', 'SH_CLERK', 40000.00, 3),
('Christopher', 'Wilson', 'christopher.wilson@example.com', '999-000-1111', '2022-02-14', 'ST_MAN', 80000.00, 4),
('Ashley', 'Taylor', 'ashley.taylor@example.com', '333-444-5555', '2023-12-01', 'IT_PROG', 62000.00, 1);

-- Insert data into Departments
INSERT INTO Departments (department_name, location_id) VALUES
('IT', 1),
('Sales', 2),
('Marketing', 3),
('Human Resources', 4),
('Finance', 5),
('Administration', 1),
('Purchasing', 2),
('Shipping', 3),
('Executive', 4),
('Public Relations', 5);

-- Insert data into Locations
INSERT INTO Locations (street_address, postal_code, city, state_province, country_id) VALUES
('123 Main St', '12345', 'New York', 'NY', 'US'),
('456 Oak Ave', '54321', 'Los Angeles', 'CA', 'US'),
('789 Pine St', '98765', 'London', NULL, 'UK'),
('321 Elm St', '10101', 'Toronto', 'ON', 'CA'),
('654 Maple Ave', '20202', 'Sydney', 'NSW', 'AU'),
('987 Birch St', '30303', 'Paris', NULL, 'FR'),
('111 Cedar St', '40404', 'Tokyo', NULL, 'JP'),
('222 Spruce St', '50505', 'Berlin', NULL, 'DE'),
('333 Willow St', '60606', 'Mumbai', 'MH', 'IN'),
('444 Aspen St', '70707', 'Sao Paulo', 'SP', 'BR');

-- Insert data into Products
INSERT INTO Products (product_name, description, price, stock_quantity, is_available) VALUES
('Laptop', 'A powerful laptop for all your computing needs.', 1200.00, 50, TRUE),
('Smartphone', 'The latest smartphone with a stunning display.', 800.00, 100, TRUE),
('Headphones', 'Noise-cancelling headphones for an immersive audio experience.', 250.00, 200, TRUE),
('Keyboard', 'A mechanical keyboard for a comfortable typing experience.', 100.00, 150, TRUE),
('Mouse', 'An ergonomic mouse for precise control.', 50.00, 300, TRUE),
('Monitor', 'A 4K monitor with vibrant colors.', 600.00, 75, TRUE),
('Webcam', 'A high-definition webcam for clear video calls.', 80.00, 120, FALSE),
('Printer', 'An all-in-one printer for your home or office.', 300.00, 60, TRUE),
('Desk Chair', 'A comfortable and adjustable desk chair.', 400.00, 40, TRUE),
('External Hard Drive', 'A portable hard drive for extra storage.', 150.00, 250, TRUE);

-- Insert data into Orders
INSERT INTO Orders (customer_id, order_date, total_amount, status) VALUES
(1, '2024-01-10 10:30:00', 250.50, 'Shipped'),
(2, '2024-01-12 14:00:00', 120.00, 'Delivered'),
(3, '2024-01-15 09:00:00', 500.75, 'Pending'),
(4, '2024-01-18 11:45:00', 75.20, 'Shipped'),
(5, '2024-01-20 16:20:00', 300.00, 'Processing'),
(1, '2024-01-22 13:15:00', 150.00, 'Shipped'),
(3, '2024-01-25 10:00:00', 600.00, 'Delivered'),
(2, '2024-01-28 18:00:00', 90.50, 'Pending'),
(4, '2024-02-01 12:30:00', 400.25, 'Shipped'),
(5, '2024-02-03 15:00:00', 200.00, 'Processing');
