using UnityEngine;

namespace Project01
{
    public sealed class CapsuleController : MonoBehaviour
    {
        private float rotationY = 0f;
        private Vector3 move = Vector3.zero;
        private Vector3 velocity = Vector3.zero;

        [SerializeField] private CharacterController characterController = null;
        [SerializeField] private Transform shootPoint = null;
        [SerializeField] private Fireball fireballPrefab = null;
        [SerializeField] private ParticleSystem impactPrefab = null;
        [SerializeField] private float speedMultiplier = 5f;
        [SerializeField] private float rotationSpeedMultiplier = 100f;

        private void Update()
        {
            float horizontal = Input.GetAxis("Horizontal");
            float vertical = Input.GetAxis("Vertical");

            rotationY += horizontal * Time.deltaTime * rotationSpeedMultiplier;
            transform.rotation = Quaternion.Euler(0f, rotationY, 0f);

            move.Set(0f, 0f, vertical);

            if (!characterController.isGrounded)
            {
                move.y -= 9.81f * Time.deltaTime;
            }

            move = transform.TransformDirection(move);
            velocity += move;

            if (velocity.magnitude > 5f)
            {
                velocity = Vector3.ClampMagnitude(velocity, 5f);
            }

            characterController.Move(velocity * speedMultiplier * Time.deltaTime);

            velocity = Vector3.Lerp(velocity, Vector3.zero, 0.05f);

            if (Input.GetKeyDown(KeyCode.Space))
            {
                ThrowFireball();
            }

            if (Input.GetKey(KeyCode.E))
            {
                if (Physics.Raycast(shootPoint.position, transform.forward, out RaycastHit hit, 100f))
                {
                    ParticleSystem impact = Instantiate(impactPrefab, hit.point, Quaternion.identity);
                    impact.transform.forward = hit.normal;
                    impact.Play();
                }
            }

            ////Vector3 position = transform.position;
            ////position.x += x * speedMultiplier * Time.deltaTime;
            ////position.z += z * speedMultiplier * Time.deltaTime;

            ////transform.position = position;
        }

        private void ThrowFireball()
        {
            Fireball fireball = Instantiate(fireballPrefab, shootPoint.position, Quaternion.identity);
            fireball.Shoot(transform.forward);
        }
    }
}
