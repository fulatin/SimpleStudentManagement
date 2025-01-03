<script setup>
import { ref } from 'vue';
import axios from 'axios';

const stuname = ref('');
const stuage = ref('');

const props = defineProps(["onAddStu"]);

function addstu() {
  if (stuname.value.trim() === '') {
    alert("Name cannot be empty");
    return;
  }

  if (isNaN(stuage.value) || stuage.value <= 0) {
    alert("Age must be a positive number");
    return;
  }

  let stu = {
    name: stuname.value,
    age: stuage.value
  };

  axios.post("api/student/add", stu).then(function (resp) {
    console.log(resp.data);
    props.onAddStu();
    stuname.value = '';
    stuage.value = '';
  });
}
</script>

<template>
  <div id="myinput">
    <div class="inputArea">
      <input v-model="stuname" placeholder="Student Name" class="input-field" />
      <input v-model="stuage" placeholder="Student Age" type="number" class="input-field" />
    </div>
    <button @click="addstu" class="btn">Add Student</button>
  </div>
</template>

<style scoped>
.inputArea {
  display: flex;
  flex-direction: column;
  gap: 10px;
  margin-bottom: 20px;
}

.input-field {
  padding: 10px;
  border: 1px solid #ccc;
  border-radius: 5px;
  font-size: 16px;
}

.btn {
  background-color: #28a745;
  color: white;
  border: none;
  padding: 10px 20px;
  border-radius: 5px;
  cursor: pointer;
  transition: background-color 0.3s ease;
}

.btn:hover {
  background-color: #218838;
}
</style>
