<script setup>
import { ref } from 'vue';
import axios from 'axios';
import TopBar from './components/TopBar.vue';

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

  <main>
    <TopBar></TopBar>
    <div style=text-align:center;>
      <button @click=getData>show all student </button>
    </div>
    <div class="flex_container">
      <div id="data" v-for="it in data">name is{{ it["name"] }} age is{{ it["age"] }}</div>
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

button {
  background-color: lightgoldenrodyellow;
  border-radius: 5px;
  border-color: red;
  border-style: solid;

  transition: background-color 1s;
}

#data {
  border-style: solid;
  box-sizing: border-box;
  transition: background-color 1s, transform 2s;
  width: 45%;
  height: 20%;
  transform: scale(1);
  background-color: lightblue;
  border-style: ridge;
  border-radius: 10px;
  text-align: center;
  border-color: lightskyblue;
  margin: auto;
  margin-top: 10px;
  padding: 10px;
}
</style>
