ALTER TABLE task_assignments
ADD CONSTRAINT task_id 
FOREIGN KEY (task_id)
REFERENCES tasks (id) 
ON DELETE SET NULL;