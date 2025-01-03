<script setup>
import { ref } from 'vue';
import axios from 'axios';
import TopBar from './components/TopBar.vue';
import addStudent from './components/addStudent.vue'
const data = ref(null)

function getData() {
  axios.get("api/student/all").then(function (resp) {
    data.value = resp.data;
  })
}
</script>





<template>
  <header>
  </header>

  <main class="anim main">
    <TopBar class="anim "></TopBar>
    <div style=text-align:center;>
      <button @click=getData>show all student </button>
    </div>
    <div class="flex_container">

      <div id="data" class="anim" v-for="it in data">name is{{ it["name"] }} age is{{ it["age"] }}</div>

      <addStudent :onAddStu="getData"></addStudent>
    </div>
  </main>
</template>

<style scoped>
.flex_container {
  align-content: center;
  flex-wrap: wrap;
  display: flex;
}

button:hover {
  background-color: red;
}

.main {
  width: 60%;
  text-align: center;
  margin: auto;
}

button {
  background-color: lightgoldenrodyellow;
  border-radius: 5px;
  border-color: red;
  border-style: solid;

  transition: background-color 1s;
}

#data:hover {
  background-color: lightblue;
}

@keyframes create {
  from {
    opacity: 0;
    transform: translateY(100px);
  }

  to {
    opacity: 1;

  }
}

.anim {

  animation: create 1s;
}

#data {
  border-style: solid;
  box-sizing: border-box;
  transition: background-color 0.3s;
  width: 45%;
  height: 20%;
  background-color: grey;
  transition: background-color 1s;
  border-style: initial;
  border-radius: 3px;
  text-align: center;
  border-color: lightskyblue;
  margin: auto;
  padding: 10px;
  margin-top: 10px;
}
</style>
