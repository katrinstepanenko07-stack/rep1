SELECT priority, due_date
FROM tasks
WHERE
    priority = 'Высокий'
    AND due_date <= '2024-02-05'::date + INTERVAL '7 day'; 