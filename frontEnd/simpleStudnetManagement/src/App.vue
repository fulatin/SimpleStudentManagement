<script setup>
import { ref } from 'vue';
import axios from 'axios';
import TopBar from './components/TopBar.vue';
import addStudent from './components/addStudent.vue';

const data = ref(null);

function getData() {
  axios.get("api/student/all").then(function (resp) {
    data.value = resp.data;
  });
}
</script>

<template>
  <header>
  </header>

  <main class="main">
    <TopBar></TopBar>
    <div class="button-container">
      <button @click="getData" class="btn">Show All Students</button>
    </div>
    <div class="flex_container">
      <div id="data" class="anim" v-for="it in data" :key="it.id">
        <p>Name: {{ it.name }}</p>
        <p>Age: {{ it.age }}</p>
      </div>
      <addStudent :onAddStu="getData"></addStudent>
    </div>
  </main>
</template>

<style scoped>
.flex_container {
  display: flex;
  flex-wrap: wrap;
  gap: 20px;
  justify-content: center;
  margin-top: 20px;
}

.button-container {
  text-align: center;
  margin: 20px 0;
}

.btn {
  background-color: #007bff;
  color: white;
  border: none;
  padding: 10px 20px;
  border-radius: 5px;
  cursor: pointer;
  transition: background-color 0.3s ease;
}

.btn:hover {
  background-color: #0056b3;
}

.main {
  width: 90%;
  max-width: 1200px;
  margin: auto;
  text-align: center;
}

#data {
  background-color: #f1f1f1;
  border-radius: 10px;
  padding: 15px;
  width: 200px;
  text-align: center;
  transition: transform 0.3s ease, box-shadow 0.3s ease;
}

#data:hover {
  transform: translateY(-5px);
  box-shadow: 0 4px 8px rgba(0, 0, 0, 0.2);
}

@keyframes create {
  from {
    opacity: 0;
    transform: translateY(20px);
  }

  to {
    opacity: 1;
    transform: translateY(0);
  }
}

.anim {
  animation: create 0.5s ease-out;
}
</style>/style>
