pipeline {

 agent any

 triggers {
  pollSCM('* * * * *')
 }

 stages {

  stage('Build') {
   steps {
    sh 'g++ src/calculator.cpp -o calculator'
   }
  }

  stage('Test') {
   steps {
    sh 'g++ tests/test_calculator.cpp -o test'
    sh './test'
   }
  }

  stage('Docker Build') {
   steps {
    sh 'docker build -t ayush81080/calculator:latest .'
   }
  }

  stage('Docker Login') {
   steps {
    withCredentials([string(credentialsId: 'docker-token', variable: 'DOCKER_TOKEN')]) {
     sh 'echo $DOCKER_TOKEN | docker login -u ayush81080 --password-stdin'
    }
   }
  }

  stage('Docker Push') {
   steps {
    sh 'docker push ayush81080/calculator:latest'
   }
  }

  stage('Deploy') {
   steps {
    sh 'ansible-playbook -i ansible/inventory ansible/deploy.yml'
   }
  }

 }

 post {

  success {
   emailext(
    subject: "Jenkins Build SUCCESS: ${env.JOB_NAME}",
    body: """
Build completed successfully.

Job Name: ${env.JOB_NAME}
Build Number: ${env.BUILD_NUMBER}
Console Output: ${env.BUILD_URL}
""",
    to: "ayush81080@gmail.com"
   )
  }

  failure {
   emailext(
    subject: "Jenkins Build FAILED: ${env.JOB_NAME}",
    body: """
Build failed.

Job Name: ${env.JOB_NAME}
Build Number: ${env.BUILD_NUMBER}
Console Output: ${env.BUILD_URL}
""",
    to: "ayush81080@gmail.com"
   )
  }

 }

}
