ALTER TABLE task_assignments
ADD CONSTRAINT user_id 
FOREIGN KEY (user_id)
REFERENCES users (id) 
ON DELETE SET NULL;