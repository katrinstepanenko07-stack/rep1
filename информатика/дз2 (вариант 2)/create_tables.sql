CREATE TABLE products_dim (
    product_id INTEGER PRIMARY KEY,
    product_name VARCHAR(255),
    category VARCHAR(100),
    price DECIMAL(10, 2)
);

CREATE TABLE customers_dim (
    customer_id INTEGER PRIMARY KEY,
    customer_name VARCHAR(255),
    region VARCHAR(100)
);

CREATE TABLE time_dim (
    time_id SERIAL PRIMARY KEY,
    sale_date DATE UNIQUE,
    year INTEGER,
    quarter INTEGER,
    month INTEGER,
    day INTEGER,
    day_of_week VARCHAR(20)
);

CREATE TABLE sales_fact (
    sale_id INTEGER PRIMARY KEY,
    sale_date DATE REFERENCES time_dim(sale_date),
    product_id INTEGER REFERENCES products_dim(product_id),
    customer_id INTEGER REFERENCES customers_dim(customer_id),
    quantity INTEGER,
    amount DECIMAL(10, 2)
);

-- Создание индексов для ускорения запросов
CREATE INDEX idx_sales_fact_product ON sales_fact(product_id);
CREATE INDEX idx_sales_fact_customer ON sales_fact(customer_id);
CREATE INDEX idx_sales_fact_date ON sales_fact(sale_date);
CREATE INDEX idx_products_dim_category ON products_dim(category);
CREATE INDEX idx_customers_dim_region ON customers_dim(region);