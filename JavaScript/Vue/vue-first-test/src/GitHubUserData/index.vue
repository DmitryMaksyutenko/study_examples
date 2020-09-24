<template>
    <div>
        <p v-for="(value, key) in data">
            {{ key }}: {{ value }}
        </p>
    </div>
</template>
<script src="./script.js"></script>
<style scoped src="./style.css"></style>
