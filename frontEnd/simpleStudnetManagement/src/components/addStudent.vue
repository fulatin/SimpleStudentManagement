<script setup>
import { ref } from 'vue';
import axios from 'axios';
const stuname = ref('')
const stuage = ref(-1)

const props = defineProps(["onAddStu"])
function addstu() {
  if (stuname.value == '') {
    alert("名称不能为空");
    return;
  }

  if (typeof stuage.value != "number") {
    alert("年龄错误");
    return;
  }
  let stu = {
    "name": stuname.value,
    "age": stuage.value
  }
  axios.post("api/student/add", stu).then(function (resp) {
    console.log(resp.data);
  })
  props.onAddStu()
}
</script>


<template>
  <div id="myinput">
    <div> {{ stuage }}</div>
    <input v-model="stuname" placeholder="学生姓名" />
    <input v-model="stuage" placeholder="学生年龄" />
    <button @click=addstu>添加</button>
  </div>
</template>


<style scoped></style>
